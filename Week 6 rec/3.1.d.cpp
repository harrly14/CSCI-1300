#include <iostream>
using namespace std;
int totalSum(int n)
    {
    int result = 0; //changed result to 0 from 1
    for(int i = 1; i <= n; i++) //changed from i = 1 to int i = 1. changed i-1 to i++.
    {
        result += i;
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter a positive integer (n): ";
    cin >> n;
    int result = totalSum(n);
    cout << "Sum of numbers from 1 to " << n << " is: " << result << endl;
    return 0;
}