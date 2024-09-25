#include <iostream>
#include <string>
using namespace std;

bool passwordMatchCheck(string password, string confirmPassword)
{
    return password == confirmPassword; //changed from = to ==
}
int main()
{
    bool passwordMatch = passwordMatchCheck("Good","Morning"); //changed 'Good' to "Good"
    cout << passwordMatch << endl;
}