//3.1.a
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int size = 6;
    double scores[size] = {85.4, 90.3, 100, 89, 74.5, 95.0, 82.3};
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += scores[i];
    }
    int avg = sum / size; //changed from 6.0 to size
    cout << "Average = " << avg << endl;
    return 0;
}