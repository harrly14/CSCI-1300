/*The program below will use two functions: one to check for password match and another
to check if the ID is valid before registering the user. Assume the relevant functions have been defined
successfully. Identify the error(s) in the code below, and write the correct line(s).*/


#include <iostream>
#include <string>
#include <cassert>
using namespace std;


bool passwordMatchCheck(string, string); //changed from cahr to string
bool idLengthCheck(int); // changed from char to int

int main() {
    int ID;
    string password;
    string confirmPassword;
    cout << "Enter your member ID: ";
    cin >> ID;
    assert(idLengthCheck(ID));
    cout << "Enter your password: ";
    cin >> password;
    cout << "Confirm your password: ";
    cin >> confirmPassword;
    if (passwordMatchCheck(password, confirmPassword)== true && idLengthCheck(ID) == true) //changed to check is password match is true AND id match is good
    {
    cout << "Password set successfully for " << ID << "." << endl; //changed username to ID
    }
    else if (!passwordMatchCheck(password, confirmPassword))
    {
    cout << "Passwords do not match." << endl;
    }
    else if(!idLengthCheck(ID))
    {
    cout << "ID is invalid." << endl;
    }
    return 0;
}
bool passwordMatchCheck(string password, string confirmPassword)
{
    return password == confirmPassword; //changed from = to ==
}
bool idLengthCheck(int ID) //changed password to ID and type to int
{
    if (ID >= 9999999 && ID < 100000000) //changd or to and
    {
        return true;
    }
    return false;
}
