//Problem 3.1.b. The program prints the contents of an array and then calculates the sum of all the elements.
//Identify the error(s) in the code below, and write the correct line(s).
#include <iostream>
using namespace std;

int main()
{
    int numbers[5] = {10, 20, 30, 40, 50};
    int sum = 0; //moved sum to outside the for loop
    cout << "The contents of the array are: ";
    for (int i = 0; i <= 5; i++){ //merged the contents of the for loops
        cout << numbers[i] << " "; //changed from numbers to numbers[i]
        sum += numbers[i]; //changed from numbers to numbers[i]
    }
    cout << endl << "Sum = " << sum << endl;
    return 0;
}

/* original:
Problem 3.1.b. The program prints the contents of an array and then calculates the sum of all the elements.
Identify the error(s) in the code below, and write the correct line(s).
#include <iostream>
using namespace std;
int main()
{
int numbers[5] = {10, 20, 30, 40, 50};
cout << "The contents of the array are: ";
for (int i = 0; i <= 5; i++)
{
cout << numbers << " ";
}
cout << endl;
for (int i = 0; i <= 5; i++)
{
int sum = 0;
sum += numbers;
}
cout << "Sum = " << sum << endl;
return 0;
}

*/