<<<<<<< HEAD
#include <iostream>
using namespace std;

int main() {
    double int_velo, final_velo;
    char fuel;
    cout << "Enter the initial velocity:" << endl;
    cin >> int_velo;
    if(int_velo<0) {
        cout << "Please input a valid velocity" << endl;
        return 0;
    }
    cout << "Enter the fuel type:" << endl;
    cin >> fuel;
    if (int_velo<10) {
        switch(fuel){
            case 'A':
                fuel = 5;
                break;
            case 'B':
                fuel = 10;
                break;
            case 'C':
                fuel = 20;
                break;
            default: 
                cout << "Please input a valid fuel type" << endl;
                return 0;
        }
    } else if (int_velo>=10 && int_velo<=40) {
        switch(fuel){
            case 'A':
                fuel = 6;
                break;
            case 'B':
                fuel = 12;
                break;
            case 'C':
                fuel = 24;
                break;
            default: 
                cout << "Please input a valid fuel type" << endl;
                return 0;
        }
    } else if (int_velo>40) {
        switch(fuel){
            case 'A':
                fuel = 3;
                break;
            case 'B':
                fuel = 6;
                break;
            case 'C':
                fuel = 9;
                break;
            default: 
                cout << "Please input a valid fuel type" << endl;
                return 0;
        }
    } 
    final_velo = int_velo+(20*fuel);
    cout << "The final velocity is " << final_velo << " m/s." << endl;
    return 0;
=======
#include <iostream>
using namespace std;

int main() {
    double int_velo, final_velo;
    char fuel;
    cout << "Enter the initial velocity:" << endl;
    cin >> int_velo;
    if(int_velo<0) {
        cout << "Please input a valid velocity" << endl;
        return 0;
    }
    cout << "Enter the fuel type:" << endl;
    cin >> fuel;
    if (int_velo<10) {
        switch(fuel){
            case 'A':
                fuel = 5;
                break;
            case 'B':
                fuel = 10;
                break;
            case 'C':
                fuel = 20;
                break;
            default: 
                cout << "Please input a valid fuel type" << endl;
                return 0;
        }
    } else if (int_velo>=10 && int_velo<=40) {
        switch(fuel){
            case 'A':
                fuel = 6;
                break;
            case 'B':
                fuel = 12;
                break;
            case 'C':
                fuel = 24;
                break;
            default: 
                cout << "Please input a valid fuel type" << endl;
                return 0;
        }
    } else if (int_velo>40) {
        switch(fuel){
            case 'A':
                fuel = 3;
                break;
            case 'B':
                fuel = 6;
                break;
            case 'C':
                fuel = 9;
                break;
            default: 
                cout << "Please input a valid fuel type" << endl;
                return 0;
        }
    } 
    final_velo = int_velo+(20*fuel);
    cout << "The final velocity is " << final_velo << " m/s." << endl;
    return 0;
>>>>>>> 6c2cf93a5ffcc7c8cdeb3eac2fcaa8177f3ec084
}