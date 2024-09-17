#include <iostream>
using namespace std;

// DO NOT include the above statements in your answer here
// only paste in your main() function

int main() {
    int cat, instr;
    string prices[3][2] = {{"570","500"}, {"425", "225"}, {"275", "350"}};
    cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion" << endl;
    cin >> cat;

    switch(cat) {
        case 1:
            cout << "Select an instrument: (1)Trumpet (2)Trombone" << endl;
            cin >> instr;
            switch(instr) {
                case 1:
                    cout << "Your instrument will be $" << prices[cat-1][instr-1] << "."<< endl;
                    break;
                case 2:
                    cout << "Your instrument will be $" << prices[cat-1][instr-1] << "."<< endl;
                    break;
                default:
                    cout << "Please enter a valid input."<< endl;
                    break;
            }
            break;
        case 2:
            cout << "Select an instrument: (1)Flute (2)Saxophone" << endl;
            cin >> instr;
            switch(instr) {
                case 1:
                    cout << "Your instrument will be $" << prices[cat-1][instr-1] << "."<< endl;
                    break;
                case 2:
                    cout << "Your instrument will be $" << prices[cat-1][instr-1] << "."<< endl;
                    break;
                default:
                    cout << "Please enter a valid input."<< endl;
                    break;
            }
            break;
        case 3:
            cout << "Select an instrument: (1)Snare Drum (2)Cymbals" << endl;
            cin >> instr;
            switch(instr) {
                case 1:
                    cout << "Your instrument will be $" << prices[cat-1][instr-1] << "."<< endl;
                    break;
                case 2:
                    cout << "Your instrument will be $" << prices[cat-1][instr-1] << "."<< endl;
                    break;
                default:
                    cout << "Please enter a valid input."<< endl;
                break;
            }
            break;
        default: 
            cout << "Please enter a valid input." << endl;
            }
    return 0;
}


