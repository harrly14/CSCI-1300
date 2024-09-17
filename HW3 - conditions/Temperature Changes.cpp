/* tell if the temp over the last 3 days has increased, decreased, or neither. 
if temps increase: print "It's getting warmer!"
    each temp is higher than the last
if temps are decreasing: print "It's getting colder"
    each temp is lower than the last
if temps are neither: print "The temperature is changing unpredictably"
    not in any order or it 2 or more temps are the same

users input 3 non-neg doubles separated by spaces
*/

#include <iostream>
using namespace std;

int main() {
    string testing;
    double temp1, temp2, temp3;
    cout << "Enter temperatures over the last three days:" << endl;
    cin >> temp1 >> temp2 >> temp3;
    if (temp1 < 0 || temp2 < 0 || temp3 < 0){
        cout << "Invalid temperature input." << endl;
    } else if (temp1 > temp2 && temp2 > temp3) {
        cout << "It's getting cooler!" << endl;
    } else if (temp1 < temp2 && temp2 < temp3) {
        cout << "It's getting warmer!" << endl;
    } else {
        cout << "The temperature is changing unpredictably." << endl;
    }
    return 0;
}