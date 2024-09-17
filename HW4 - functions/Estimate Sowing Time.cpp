#include <iostream>
using namespace std;
// Paste only the function required and main().
// Header files: iostream have been included, please do not paste that in the answer box

double calculateSowingTime(double area, char machine_type);

int main() {
    double area;
    char machine_type;
    cout << "Enter area of the farmland in sq ft:" << endl;
    cin >> area;
    cout << "Enter the type of sowing machine to be used:" << endl;
    cin >> machine_type;
    if((machine_type != 'W' && machine_type != 'X' && machine_type != 'Y' && machine_type != 'Z') || area<=0) {
        cout << "Area or machine type is invalid. Time cannot be calculated." << endl;
    } else {
        cout << "The time taken is: " << calculateSowingTime(area, machine_type) << " minutes." << endl;
    }
    return 0;
}

double calculateSowingTime(double area, char machine_type) {
    switch(machine_type) {
        case 'W':
            return (area/8)*12;
        case 'X':
            return (area/3)*10; 
        case 'Y':
            return (area/2)*7;
        case 'Z':
            return (area/7)*8;
    }
    return 0;
}