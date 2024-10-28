/*
find the center or mass of the body by computing average
of X, Y, and Z
1. read each line as a string
2. use split() to split by commas
3. use validateDouble() to confirm that each piece is a valid double
4. use stod to translate strings to doubles


*/


/*
3.2.a

read the file
for each line in the file,
    separate line by spaces
    add first item to x sum, second item to y sum, third item to z sum
    if validatedouvle fails, cout "Invalid value detected", return -1
set avg's equal to sums divided by num of lines

cout The center of mass is at:  x_avg, y_avg, z_avg!
*/

/*
3.2.b

-1 -1 -1 
    should invert the sign of whatever the center of mass would have been
aaa 122 -110
    should get an error
12  
    should just not change the y and z sums
3.25,4.19,-3.56
1.04,2.31,5.12
    The center of mass is at:  2.145, 3.25,  0.78!
*/

//3.2.c
#include<iostream>
#include<fstream>
using namespace std;

int split(string input_string, char separator, string arr[], const int ARR_SIZE){
    if (input_string.length() == 0){
        return 0;
    } 
    int sep_counter = 0;
    int sep_index = -1;
    for (unsigned int i = 0; i < input_string.length(); ++i){
        if (input_string[i] == separator){
            arr[sep_counter] = input_string.substr(sep_index+1, i - sep_index-1);
            sep_index = i;
            ++sep_counter;
            if (sep_counter >= ARR_SIZE) {
                return -1;
            }
            arr[sep_counter] = input_string.substr(i+1);
        } 
    }

    if (sep_counter == 0) {
        arr[0] = input_string;
    }

    return sep_counter + 1;
}

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


int main() {
    ifstream fin;
    fin.open("coordinates1.txt");
    string line;
    const int num_of_items_in_line = 3;
    string arr[num_of_items_in_line] = {};
    double x_sum = 0, y_sum = 0, z_sum = 0, line_counter = 0.0;

    while (getline(fin, line)){
        split(line, ',',arr,num_of_items_in_line);
        for (int i = 0; i < num_of_items_in_line; ++i){
            if (!validateDouble(arr[i])){
                cout << "Invalid value detected" << endl;
                return -1;
            }
        }
        x_sum += stod(arr[0]);
        y_sum += stod(arr[1]);
        z_sum += stod(arr[2]);
        ++line_counter;
    }
    double x_avg = x_sum/line_counter;
    double y_avg = y_sum/line_counter;
    double z_avg = z_sum/line_counter;

    cout << "The center of mass is at:  " << x_avg << ", " << y_avg << ",  " << z_avg << "!";

    return 0;
}


