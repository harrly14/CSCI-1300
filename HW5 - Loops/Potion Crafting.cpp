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
int leaves,flowers,mushrooms, needles;

int magic_potions() {
    int i = 0;
    while ((leaves/2)>i && (flowers/3)>i && (mushrooms/10)>i && needles>i) {
    i++;
    }
    leaves = leaves - (i*2);
    flowers = flowers - (i*3);
    mushrooms = mushrooms - (i*10);
    needles = needles - i;
    return i;
}

int health_potions() {
    int i = 0;
    while ((leaves/6)>i && flowers>i &&(mushrooms/5)>i && (needles/2)>i) {
    i++;
    }
    leaves = leaves - (i*6);
    flowers = flowers - i;
    mushrooms = mushrooms - (i*5);
    needles = needles - (i*2);
    return i;
}

int main() {
    int potion;
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

    if(potion == 2){
        cout << "You can make "<<magic_potions()<<" Magic potion(s) and "<<health_potions() <<" Health potion(s)." <<endl;
    } else if (potion == 1) {
        cout << "You can make "<<health_potions()<<" Health potion(s) and "<<magic_potions() <<" Magic potion(s)." <<endl;
    }
    return 0;
}