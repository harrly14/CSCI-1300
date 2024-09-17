/*tells if you can afford a road trip. 
inputs: budget (int), miles (int), nights, (int)
1. get inputs
2. perform input validation to check they are pos ints
    display "Invalid input(s)" if not validated. 
3. calculate gas money: .16/mile
4. deduct gas money from budget
5. divide budget by nights
6. if budget < 20: "This trip is outside your budget.
"
    if budget >=20 && budget < 50: You can afford to go camping on this trip.
    if budget >=50 && budget < 100: You can afford to stay in a cheap motel on this trip.
    if budget > 100: You can afford to stay in a nice hotel on this trip.

sample output: 
What is your budget?
100
How many miles will you drive?
800
How many nights do you want to spend there?
3
This trip is outside your budget.

*/

#include <iostream>
using namespace std;

int main() {
    // initialize everything
    int budget, miles, nights;
    cout << "What is your budget?" << endl;
    cin >> budget;
    cout << "How many miles will you drive?" << endl;
    cin >> miles;
    cout << "How many nights do you want to spend there?" << endl;
    cin >> nights;

    //validate inputs
    if (budget < 0 || miles < 0 || nights < 0){
        cout << "Invalid input(s)" << endl;
        return 0;
    }

    budget = (budget - (.16*miles))/nights;
    if (budget < 20) {
        cout << "This trip is outside your budget." << endl;
    }
    else if (budget >=20 && budget < 50){
        cout << "You can afford to go camping on this trip." << endl;
    } else if (budget >=50 && budget < 100){
        cout << "You can afford to stay in a cheap motel on this trip." << endl;
    }
    else {
        cout << "You can afford to stay in a nice hotel on this trip." << endl;
    }

    return 0;
}