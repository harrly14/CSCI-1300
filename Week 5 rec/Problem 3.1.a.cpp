#include <iostream>
#include <cassert> //added cassert
using namespace std;

double findMean(int a, int b, int c)
{
    int mean = (a+b+c) / 3.0;
    return mean;
}

int main()
{
    int average = findMean(2,5,2); //corrected function name
    assert(average == 3);
    return 0;
}