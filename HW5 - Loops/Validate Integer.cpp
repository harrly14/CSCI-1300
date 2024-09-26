/*
define a function validateInt
    accept a string input and determine if it 
    represents a valid in by checking if each char in the string is a valid value

ask user to input an int, store it as a string, then invoke validateint to check validity
print whether valid or not 
*/
#include <iostream>
using namespace std;


// Assume the proper libraries are included.
// Assume the proper implementation of validateInt() is included.
#include <string>
bool validateInt(string number){
    bool isNum;
    if (number.length()== 0) {
        return false;
    }
    if (number[0] == '-' && number.length()>1){
        number = number.substr(1);
    }
    for (char c : number) {
        if (c>='0' && c<='9'){
            isNum = true;
        }else {
            return false;
        }
    }
    return isNum;
}




//do not paste main in
int main()
{
string number;
cout << "Enter the integer : " << endl;
getline(cin, number);
if(!validateInt(number))
{
cout << "The entered string is not a valid integer!!" << endl;
}
else
{
cout << "The entered string is a valid integer!!" << endl;
}
return 0;
}
