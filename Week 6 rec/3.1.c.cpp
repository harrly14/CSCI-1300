#include <iostream>
#include <string>
using namespace std;
int main()
{
    string initial_string;
    string retype_string;
    cout << "Enter your string: ";
    cin >> initial_string;
    cout << "Enter your string again: ";
    cin >> retype_string;
    while (retype_string != initial_string) //changed from = to !=
    {
        cout << "Your strings do not match. Try again: " << endl;
        cin >> retype_string;
    }
    cout << "Your strings match!!!!" << endl;
    return 0;
}
