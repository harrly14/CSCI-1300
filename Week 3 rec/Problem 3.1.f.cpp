#include <iostream>
using namespace std;

int main()
{
    char grade;
    cout << "Provide a grade (A, B, C, D, or F):" << endl;
    cin >> grade;
    if (grade == 'A' || grade == 'B' || grade == 'C'){
        cout << "This is a passing grade." << endl;
    }
    else if (grade == 'D'){
        cout << "This grade passes with conditions." << endl;
    }
    else if (grade == 'F'){ //changed from else to else if to make sure we cannot input invalid grades
        cout << "This is a failing grade." << endl;
    } else { //adding this else statement to catch invalid inputs
        cout << "Input invalid." << endl;
    }
    return 0;
}