#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Provide an integer:" << endl;
    cin >> num;
    if (num%2 == 0){ //changed from "num/2"
        cout << "The number is even." << endl;
    }
    else {
        cout << "The number is odd." << endl;
    }
    return 0;
}