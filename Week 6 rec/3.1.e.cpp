#include <iostream>
using namespace std;
int main()
{
    int number; //changed from num to number
    int sum = 0;
    do {
        cout << "Enter a number (enter a negative number to stop): ";
        cin >> number;
        if (number >= 0){
            sum += number;
        }
    }
    while (number >= 0); //added perenthesis
    cout << "Sum of the entered numbers: " << sum << endl;
    return 0;
}