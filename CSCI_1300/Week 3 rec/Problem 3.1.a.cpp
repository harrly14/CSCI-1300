#include <iostream>
using namespace std;

int main() {
    int num = 6;

    if(num>8) {
        cout << "The number is grater than 8." ;
    }
    else if (num==8) { //I changed this line from "=" to "==" 
    //because it was setting the variable equal to 8 instead of checking if its equal to 8
        cout << "The number is equal to 8.";
    }
    else {
        cout << "The number is less than 8.";
    }

    return 0;
}