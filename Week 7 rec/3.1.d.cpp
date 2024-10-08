//Problem 3.1.d. The program prints the product of the length of contents of a string array. Identify the
//error(s) in the code below, and write the correct line(s).
#include <iostream>
#include <string>
using namespace std;

int main(){
    string languages[5] = {"C++","Python","Java","Matlab","Julia"}; //changed numher of items from 6 to 5
    int product = 1; //changed from 0 to 1
    int total = 5; //changed to 5 from languages length
    for(int i = 0; i < total; i++){ //changed from <= total to < total
        product *= languages[i].length(); //added perentheses
    }
    cout << "Product of lengths = " << product << endl;
    return 0;
}