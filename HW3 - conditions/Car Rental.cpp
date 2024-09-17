<<<<<<< HEAD
/* calculate the total cost based on car type and number of days

| car type | base price | price per day |
    A          80             15
    B          110            25
    c          160            35
    D          220            45

total bill = 1.23 * (base price + no of days * price per day)
input is a character (for car type), non-neg int (days)
output should be a double
input validation
    a,b,c, or d for car 
    min days = 1
    "Please enter valid input."
cost should be setprecision 2

sample run: 
Which car type (A, B, C, or D) would you like to rent?
A
How many days would you like to rent this car?
6
Your total is $209.10
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double total, base_price, ppday;
    char car_type;
    int days;
    cout << "Which car type (A, B, C, or D) would you like to rent?" << endl;
    cin >> car_type;
    cout << "How many days would you like to rent this car?" << endl;
    cin >> days;

    // input validation
    if ((car_type != 'A' && car_type != 'B' && car_type != 'C' && car_type != 'D') || days < 1) {
        cout << "Please enter valid input." << endl;
        return 0;
    } 

    // math! total = 1.23 * (base price + no of days * price per day)
    if (car_type == 'A') {
        base_price = 80;
        ppday = 15;
    } else if (car_type == 'B') {
        base_price = 110;
        ppday = 25;
    } else if (car_type == 'C') {
        base_price = 160;
        ppday = 35;
    } else {
        base_price = 220;
        ppday = 45;
    }
    total = 1.23 * (base_price+days*ppday);
    cout << "Your total is $" << setprecision(2) << fixed << total << endl;
    return 0;
=======
/* calculate the total cost based on car type and number of days

| car type | base price | price per day |
    A          80             15
    B          110            25
    c          160            35
    D          220            45

total bill = 1.23 * (base price + no of days * price per day)
input is a character (for car type), non-neg int (days)
output should be a double
input validation
    a,b,c, or d for car 
    min days = 1
    "Please enter valid input."
cost should be setprecision 2

sample run: 
Which car type (A, B, C, or D) would you like to rent?
A
How many days would you like to rent this car?
6
Your total is $209.10
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double total, base_price, ppday;
    char car_type;
    int days;
    cout << "Which car type (A, B, C, or D) would you like to rent?" << endl;
    cin >> car_type;
    cout << "How many days would you like to rent this car?" << endl;
    cin >> days;

    // input validation
    if ((car_type != 'A' && car_type != 'B' && car_type != 'C' && car_type != 'D') || days < 1) {
        cout << "Please enter valid input." << endl;
        return 0;
    } 

    // math! total = 1.23 * (base price + no of days * price per day)
    if (car_type == 'A') {
        base_price = 80;
        ppday = 15;
    } else if (car_type == 'B') {
        base_price = 110;
        ppday = 25;
    } else if (car_type == 'C') {
        base_price = 160;
        ppday = 35;
    } else {
        base_price = 220;
        ppday = 45;
    }
    total = 1.23 * (base_price+days*ppday);
    cout << "Your total is $" << setprecision(2) << fixed << total << endl;
    return 0;
>>>>>>> 6c2cf93a5ffcc7c8cdeb3eac2fcaa8177f3ec084
}