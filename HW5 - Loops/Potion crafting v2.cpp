/*
write a program that asks the user which potion they would like to prioritize—Health
or Magic. 
ask them to reenter if the put an invalid input
then prompt user to input number of each ingredient
based on ings, calculate how many potions can be crafted
leftover ings should be used to craft the other type of potion
finally, output how many of each potion can be crafted
            health      magic
tealeaves:    6           2
sunflowers:   1           3
toadstools:   5           10
pine needles: 2           1
*/

#include <iostream>
using namespace std;

int main() {
    int potion,leaves, flowers, mushrooms, needles, hp= 0, mp= 0;
    cout << "Select a potion crafting priority:" << endl;
    cout << "1. Health Potion" << endl << "2. Magic Potion" << endl;
    cin >> potion;
    while (potion != 1 && potion!=2) {
        cout << "Invalid input. Please select 1 or 2." << endl;
        cin >> potion; 
    }
    cout << "How many Tealeaves do you have?" << endl;
    cin >> leaves;
    while (leaves<0) {
        cout << "Invalid input. Please enter a non-negative integer." << endl;
        cout << "How many Tealeaves do you have?" << endl;
        cin >> leaves; 
    }
    cout << "How many Sunflowers do you have?" << endl;
    cin >> flowers;
    cout << "How many Toadstools do you have?" << endl;
    cin >> mushrooms;
    cout << "How many Pine Needles do you have?" << endl;
    cin >> needles;

    
    if(potion == 1) {
        while (leaves>=6 and flowers>=1 and mushrooms>=5 and needles>=2) {
            hp++;
            leaves -=6;
            flowers -=1;
            mushrooms -=5;
            needles -=2;
        }
        while (leaves>=2 and flowers>=3 and mushrooms>=10 and needles >=1){
            mp++;
            leaves -=2;
            flowers -=3;
            mushrooms -=10;
            needles -=1;
        }

        cout << "You can make "<<hp<<" Health potion(s) and "<<mp <<" Magic potion(s)." <<endl;
    } else if (potion == 2){
        while (leaves>=2 and flowers>=3 and mushrooms>=10 and needles >=1){
            mp++;
            leaves -=2;
            flowers -=3;
            mushrooms -=10;
            needles -=1;
        }
        while (leaves>=6 and flowers>=1 and mushrooms>=5 and needles>=2) {
            hp++;
            leaves -=6;
            flowers -=1;
            mushrooms -=5;
            needles -=2;
        }
        cout << "You can make "<<mp<<" Magic potion(s) and "<<hp <<" Health potion(s)." <<endl;
    }

    return 0;
}

