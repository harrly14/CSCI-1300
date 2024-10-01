#include <iostream>
using namespace std;
#include <string>


bool validateDouble(string number){
    bool isNum = false;
    double num_num;
    //convert string to double
    //I learned how to catch errors for this! how exciting!
    try {
    num_num = stod(number);
    }
    catch (const invalid_argument&){ //catching an invalid argument error like in the case of the "-." input. 
        return false;
    }

    string num_str = to_string(num_num); //convert double back into string
    num_str.erase ( num_str.find_last_not_of('0')+1, string::npos ); //erase trailing 0s
    num_str.erase ( num_str.find_last_not_of('.') + 1, string::npos ); //erase the decimal point if it is a whole number

    //one problem with this code is that if you put a trailing 0 in your input, such as "10.10", it does not return true
    //however, the prompt says to make the function for doubles with one decimal point, so this should work. 
    return num_str == number;
}




//only thing I changed from validateInt was the couts to say double instead of integer
int main()
{
string number;
cout << "Enter the double : " << endl;
getline(cin, number);
if(!validateDouble(number)){
    cout << "The entered string is not a valid double!!" << endl;
}
else{
    cout << "The entered string is a valid double!!" << endl;
}
return 0;
}
