#include <iostream>
#include <string>
using namespace std;

bool passwordMatchCheck(string password, string confirmPassword) //changed from string to bool
{
    return password == confirmPassword; //changed from = to ==
}
int main()
{
    bool passwordMatch = passwordMatchCheck("Good","Morning"); //changed 'Good' to "Good"
    cout << passwordMatch << endl;
}