#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    //commenting out the first else block because you cannot put an else statement before an if statement (and it isn't needed)
    /*else {
        cout << "This is the 'else' block.";
    }*/
    if (num == 0) {
        cout << "The number is zero.";
    }
    else {
        cout << "The number is not zero.";
    }
    return 0;
}