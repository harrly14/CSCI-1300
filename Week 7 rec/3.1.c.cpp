//Problem 3.1.c. The program finds and prints all prime factors of a given number num. Identify the error(s)
//in the code below, and write the correct line(s).
#include <iostream>
#include <cmath>
using namespace std;

void primeFactors(int num)
{
    int n = num; //changed to initialize to num
    while (n % 2 == 0){
        cout << 2;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i++){
        while (n % i == 0){
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 2){
        cout << n;
    }

    cout<<endl;
}

int main(){
    int num = 315;
    primeFactors(num);
    return 0;
}