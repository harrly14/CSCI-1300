<<<<<<< HEAD
/*calculate volume of a fish tank
ask user for three values: length, width, height (in inches)
use above values to calculate volume in cubic inches
translate cubic inches into gallons
tell the user how many gallons are in the fish tank
print capacity to 1 decimal place

volume = lenght * height * width
 1 cubic inch = 0.004329 gallons

sample output
What is the length of the fish tank in inches?
20
What is the width of the fish tank in inches?
20
What is the height of the fish tank in inches?
20
This fish tank has a 34.6 gallon capacity. */


#include <iostream>
#include <iomanip>
using namespace std;

main() {
    double length, width, height, volume, volume_gals;
    cout << "What is the length of the fish tank in inches?" << endl;
    cin >> length;
    cout << "What is the width of the fish tank in inches?" << endl;
    cin >> width;
    cout << "What is the height of the fish tank in inches?" << endl;
    cin >> height;
    volume = length*width*height;
    volume_gals = volume*0.004329;
    cout << "This fish tank has a " << setprecision(1) << fixed << volume_gals << " gallon capacity." << endl;
    return 0;
=======
/*calculate volume of a fish tank
ask user for three values: length, width, height (in inches)
use above values to calculate volume in cubic inches
translate cubic inches into gallons
tell the user how many gallons are in the fish tank
print capacity to 1 decimal place

volume = lenght * height * width
 1 cubic inch = 0.004329 gallons

sample output
What is the length of the fish tank in inches?
20
What is the width of the fish tank in inches?
20
What is the height of the fish tank in inches?
20
This fish tank has a 34.6 gallon capacity. */


#include <iostream>
#include <iomanip>
using namespace std;

main() {
    double length, width, height, volume, volume_gals;
    cout << "What is the length of the fish tank in inches?" << endl;
    cin >> length;
    cout << "What is the width of the fish tank in inches?" << endl;
    cin >> width;
    cout << "What is the height of the fish tank in inches?" << endl;
    cin >> height;
    volume = length*width*height;
    volume_gals = volume*0.004329;
    cout << "This fish tank has a " << setprecision(1) << fixed << volume_gals << " gallon capacity." << endl;
    return 0;
>>>>>>> 6c2cf93a5ffcc7c8cdeb3eac2fcaa8177f3ec084
}