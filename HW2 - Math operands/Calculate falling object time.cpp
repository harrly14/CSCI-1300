<<<<<<< HEAD
//calculate the time for a falling object to hit the ground
//based on the original height of the object (in meters)
//print the time to two decimal places
    // may require iomanip library and setprecision function
//equation: time=sqrt((2*height)/9.8)
//assume the height is not negative
//assume time is positive

//solution: 
//include iospace, cmath, and iomanip libraries
//create doubles for the original height and the time it takes to hit the ground
//cout "How far did the object fall in meters?"
//cin original height
//perform the calculation based on the height
//trim the output to 2 decimal places
//cout "The object fell for " time " seconds."



#include <iostream>
#include <iomanip>
#include <cmath> //necessary for sqrt
using namespace std;

int main() {
    double height, time;
    cout << "How far did the object fall in meters?" << endl;
    cin >> height;
    time = sqrt((2*height)/9.8);
    cout << "The object fell for " << setprecision(2) << fixed << time << " seconds." << endl;
    return 0;
=======
//calculate the time for a falling object to hit the ground
//based on the original height of the object (in meters)
//print the time to two decimal places
    // may require iomanip library and setprecision function
//equation: time=sqrt((2*height)/9.8)
//assume the height is not negative
//assume time is positive

//solution: 
//include iospace, cmath, and iomanip libraries
//create doubles for the original height and the time it takes to hit the ground
//cout "How far did the object fall in meters?"
//cin original height
//perform the calculation based on the height
//trim the output to 2 decimal places
//cout "The object fell for " time " seconds."



#include <iostream>
#include <iomanip>
#include <cmath> //necessary for sqrt
using namespace std;

int main() {
    double height, time;
    cout << "How far did the object fall in meters?" << endl;
    cin >> height;
    time = sqrt((2*height)/9.8);
    cout << "The object fell for " << setprecision(2) << fixed << time << " seconds." << endl;
    return 0;
>>>>>>> 6c2cf93a5ffcc7c8cdeb3eac2fcaa8177f3ec084
}