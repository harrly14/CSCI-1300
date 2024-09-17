//include iostream and use std namespace
#include <iostream>
using namespace std;
//start main function
int main() {
//initialize "steps" variable -- type int
    int steps;
//cout "How many steps have you taken today?"
    cout << "How many steps have you taken today?" << endl;
//cin to steps
    cin >> steps;
//if 0<steps<5000, cout "You have not walked much today! Get those steps in! You have " << 10000-steps << " steps left to walk."
    if (steps>=0 && steps<=5000){
        cout << "You have not walked much today! Get those steps in! You have " << 10000-steps << " steps left to walk." << endl;
    }
//else if 5000<steps<10000, cout "You're doing great, over half way there! You still have " << 10000-steps <<" steps left to walk."
    else if (steps>5000 && steps < 10000) {
        cout << "You're doing great, over half way there! You still have " << 10000-steps <<" steps left to walk." << endl;
    }
// else if steps>=10000, cout "You've hit your goal for the day! Great job getting exercise!"
    else if (steps>=10000) {
        cout << "You've hit your goal for the day! Great job getting exercise!" << endl;
    }
// else cout "Invalid input." to check for negative ints}
    else {
        cout << "Invalid input." << endl;
    }
//return 0 (end function)
    return 0;
}