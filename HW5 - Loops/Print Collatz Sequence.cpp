/*
write a program that prompts the user to enter an integer value between 10 and
500 (both exclusive).  then print out a sequence of numbers between the given value
and 1 (inclusive) 

for a number n,
    if even: return floor a/2
    if even: return 3a+1
    stop at 1

print total steps
*/
#include <iostream>
using namespace std;

void collatz(int n){
    int i = 0;
    while (n>1) {
        if (n%2 == 0) {
            n = n/2;
            cout << n << endl;
            i++;
        } else if (n%2 == 1) {
            n = 3*n+1;
            cout << n << endl;
            i++;
        }
    }
    cout << "Total steps: " << i << endl;
}

int main(){
    int n;
    cout << "Enter a number between 10 and 500:" << endl;
    cin >> n;
    while (n<=10 || n>=500){
        cout << "Invalid input."<<endl;
        cout << "Enter a number between 10 and 500:" << endl;
        cin >> n;
    }
    collatz(n);
    return 0;
}