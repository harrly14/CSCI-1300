<<<<<<< HEAD
#include <iostream> 
#include <cmath>
#include <cstdlib>
using namespace std;

//No need to include the above preprocessor directives.
//Please add the main() function only

int main() {
    char car_man;
    string ending_print;
    ending_print = "Automobile manufacturer chosen: ";
    cout << "Enter the first letter of the company:" << endl;
    cin >> car_man;
    switch(car_man) {
        case 'B':
            cout << ending_print << "BMW" << endl;
            break;
        case 'V':
            cout << ending_print << "Volkswagen" << endl;
            break;
        case 'H':
            cout << ending_print << "Honda" << endl;
            break;
        case 'T':
            cout << ending_print << "Tesla" << endl;
            break;
        default:
            cout << ending_print << "Invalid" << endl;
    }
    return 0;
=======
#include <iostream> 
#include <cmath>
#include <cstdlib>
using namespace std;

//No need to include the above preprocessor directives.
//Please add the main() function only

int main() {
    char car_man;
    string ending_print;
    ending_print = "Automobile manufacturer chosen: ";
    cout << "Enter the first letter of the company:" << endl;
    cin >> car_man;
    switch(car_man) {
        case 'B':
            cout << ending_print << "BMW" << endl;
            break;
        case 'V':
            cout << ending_print << "Volkswagen" << endl;
            break;
        case 'H':
            cout << ending_print << "Honda" << endl;
            break;
        case 'T':
            cout << ending_print << "Tesla" << endl;
            break;
        default:
            cout << ending_print << "Invalid" << endl;
    }
    return 0;
>>>>>>> 6c2cf93a5ffcc7c8cdeb3eac2fcaa8177f3ec084
}