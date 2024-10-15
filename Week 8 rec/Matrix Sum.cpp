/*
3.3.a
main: cout the prompts, cin each value
matrixSum: iterate through the matrix and sum a and b at that index,
cout the sum with a space after it
end the line after you get to the end of the row
*/

/*
3.3.b
input a: 1 2 3 4 5 6
input b: 2 4 6 8 10 12
output: 3 6 9 12 15 18
*/


//3.3.c
#include <iostream>
using namespace std;

void matrixSum(int a[2][3], int b[2][3]){
    cout << "The sum is:" << endl;
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 3; ++j){
            int current_a = a[i][j];
            int current_b = b[i][j];
            int sum = current_a + current_b;
            cout <<  sum << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[2][3];
    int b[2][3];
    cout << "Enter values for matrix 1, one row at a time:" << endl;
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 3; ++j){
            cin >> a[i][j];
        }
    }
    cout << "Enter values for matrix 2, one row at a time:" << endl;
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 3; ++j){
            cin >> b[i][j];
        }
    }
    matrixSum(a,b);
    

    return 0;
}