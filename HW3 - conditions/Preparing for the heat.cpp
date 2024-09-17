<<<<<<< HEAD
/* Determine if you need to carry extra water based on temp
1. prompt user to ent temp (in F)
    input validation: if user inputs a non-pos value for temp, 
    display "Invalid temperature", then terminate
2. if temp>85, display "You need to carry extra water.", then terminate
3. If temp is 85 or below, display "You don't need extra water." then terminate

Sample run: 
What is the temperature?
75
You don't need extra water.
*/



#include <iostream>
using namespace std;

int main() {
    int temp;
    cout << "What is the temperature?" << endl;
    cin >> temp;
    if (temp < 1){
        cout << "Invalid temperature." << endl;
        return 0;
    } else if (temp <= 85){
        cout << "You don't need extra water." << endl;
        return 0;
    } else {
        cout << "You need to carry extra water." << endl;
    }
=======
/* Determine if you need to carry extra water based on temp
1. prompt user to ent temp (in F)
    input validation: if user inputs a non-pos value for temp, 
    display "Invalid temperature", then terminate
2. if temp>85, display "You need to carry extra water.", then terminate
3. If temp is 85 or below, display "You don't need extra water." then terminate

Sample run: 
What is the temperature?
75
You don't need extra water.
*/



#include <iostream>
using namespace std;

int main() {
    int temp;
    cout << "What is the temperature?" << endl;
    cin >> temp;
    if (temp < 1){
        cout << "Invalid temperature." << endl;
        return 0;
    } else if (temp <= 85){
        cout << "You don't need extra water." << endl;
        return 0;
    } else {
        cout << "You need to carry extra water." << endl;
    }
>>>>>>> 6c2cf93a5ffcc7c8cdeb3eac2fcaa8177f3ec084
}