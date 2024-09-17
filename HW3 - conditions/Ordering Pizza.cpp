<<<<<<< HEAD
/* calculate total cost of pizza. 
1. prompt for the size of pizza (char)
    accept both lower and uppercase
    perform input validation
2. prompt for number of toppings (non-neg int)
3. output cost
    should be a double
    should be two decimal places

cost table: 
| size | base price | price per topping |
   S        8.00           0.99
   M        10.00          1.99
   L        14.00          2.99

sample output: 
What size pizza would you like to order?
S
How many toppings do you want?
3
Your total is $10.97
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // initialize variables
    string size_input;
    char pizza_size;
    int toppings;
    double base_price, pptopping, total;
    // get inputs 
    cout << "What size pizza would you like to order?" << endl;
    cin >> size_input;
    cout << "How many toppings do you want?" << endl;
    cin >> toppings;

    //validate inputs
    if (size_input.length() > 1 ) {
        cout << "Invalid pizza size." << endl;
        return 0;
    } 
    pizza_size = tolower(size_input[0]);
    if (pizza_size != 's' && pizza_size != 'm' && pizza_size != 'l') {
        if (toppings < 0) {
        cout << "Invalid pizza size and number of toppings." << endl;
        return 0;
        }
        cout << "Invalid pizza size." << endl;
        return 0;
    }
    if (toppings < 0) {
        cout << "Invalid number of toppings." << endl;
        return 0;
    }

    // calculate cost
    if (pizza_size == 's') {
        base_price = 8.00;
        pptopping = .99;
    } else if (pizza_size == 'm') {
        base_price = 10.00;
        pptopping = 1.99;
    } else {
        base_price = 14.00;
        pptopping = 2.99;
    }
    total = base_price + pptopping*toppings;
    cout << "Your total is $" << setprecision(2) << fixed << total << endl; 
    return 0;
=======
/* calculate total cost of pizza. 
1. prompt for the size of pizza (char)
    accept both lower and uppercase
    perform input validation
2. prompt for number of toppings (non-neg int)
3. output cost
    should be a double
    should be two decimal places

cost table: 
| size | base price | price per topping |
   S        8.00           0.99
   M        10.00          1.99
   L        14.00          2.99

sample output: 
What size pizza would you like to order?
S
How many toppings do you want?
3
Your total is $10.97
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // initialize variables
    string size_input;
    char pizza_size;
    int toppings;
    double base_price, pptopping, total;
    // get inputs 
    cout << "What size pizza would you like to order?" << endl;
    cin >> size_input;
    cout << "How many toppings do you want?" << endl;
    cin >> toppings;

    //validate inputs
    if (size_input.length() > 1 ) {
        cout << "Invalid pizza size." << endl;
        return 0;
    } 
    pizza_size = tolower(size_input[0]);
    if (pizza_size != 's' && pizza_size != 'm' && pizza_size != 'l') {
        if (toppings < 0) {
        cout << "Invalid pizza size and number of toppings." << endl;
        return 0;
        }
        cout << "Invalid pizza size." << endl;
        return 0;
    }
    if (toppings < 0) {
        cout << "Invalid number of toppings." << endl;
        return 0;
    }

    // calculate cost
    if (pizza_size == 's') {
        base_price = 8.00;
        pptopping = .99;
    } else if (pizza_size == 'm') {
        base_price = 10.00;
        pptopping = 1.99;
    } else {
        base_price = 14.00;
        pptopping = 2.99;
    }
    total = base_price + pptopping*toppings;
    cout << "Your total is $" << setprecision(2) << fixed << total << endl; 
    return 0;
>>>>>>> 6c2cf93a5ffcc7c8cdeb3eac2fcaa8177f3ec084
}