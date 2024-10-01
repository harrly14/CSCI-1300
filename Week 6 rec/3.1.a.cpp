#include <iostream>
using namespace std;
void printEvenNumbers(int N)
    {
    int i = 2;
    while (i <= N){
        if (i % 2 == 0){
            cout << i << " ";
        }
        i++; //changed to i++ from j++ and moved into the while loop
    }
    return;
}

int main()
{
    int number;
    cout << "Enter a number: " << endl;
    cin >> number;
    printEvenNumbers(number);
    return 0;
}
