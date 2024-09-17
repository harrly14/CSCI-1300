#include <iostream>
using namespace std;
int main()
{

    int x = 120; //changed variable name to x to match the if statements
    if (x>90) {
        cout<<"It is an obtuse angle." ;
    }
    else if(x==90) { //changed from "elif" to "else if" and changed "=" to "=="
        cout<<"It is a right angle.";
    }
    else{
        cout<<"It is an acute angle.";
    }
}