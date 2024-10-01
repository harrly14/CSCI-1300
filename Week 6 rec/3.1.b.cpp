#include <iostream>
using namespace std;
int main()
{
    int liquid_level = 5;
    int threshold = 60;
    while (liquid_level < threshold) //changed from <= to <
    {
        cout << "Pump is running. Liquid level: " << liquid_level << " units." << endl;
        liquid_level += 5; //changed from -= to +=
    }
    cout << "Pump stopped. Liquid level: " << liquid_level << " units." << endl;
    return 0;
}