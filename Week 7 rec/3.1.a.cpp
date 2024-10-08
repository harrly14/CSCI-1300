//Problem 3.1.a. Given two positive integers x and y, this programs prints all the integer points (i, j) in the
//rectangle formed by (0, 0) and (x, y). Identify the error(s) in the code below, and write the correct line(s).

#include <iostream>
using namespace std;

int main()
{
    int x = 3, y = 4;
    for(int i = 0; i <= x; i++) //changed j++ to i++, changed i>=x to i<=x
    {
        for(int j = 0; j <= y; j++){
            cout << "(" << i << ", " << j << ") ";
    }
    cout << endl;
    }
}