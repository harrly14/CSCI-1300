#include <iostream>
using namespace std;

// Paste only the function required and main().
// Header files: iostream have been included, please do not paste that in the answer box


double calculateRoomArea(double length, double width){
    return length*width;
}
double length, width, area;
int main() {
    cout << "Enter the length of the room in ft:" << endl;
    cin >> length;
    cout << "Enter the width of the room in ft:" << endl;
    cin >> width;
    area = calculateRoomArea(length, width);
    if (length>0 && width>0) {
        cout << "The area is: " << area << " sq ft." << endl;
    return 0;
    } else {
        cout << "Length or width is invalid. Area cannot be calculated." << endl;
    }
}



