/*3.2.a
copy in last week's code with split, validatedouble, main
use file io to write to the centers of mass to a summary file 
if the line does not pass validate double, write to log file
catch for if there are no valid lines
*/

/*
input: 
3.25,4.19,-3.56
1.04,2.31,5.12
abc,2.31,5.12
5.00,0,-0.8
    output: 3.09667, 2.16667,  0.253333

input: 

    output: No valid lines!

input: 
3, 3, 3
4, 4, 4
5, 5, 5
    output: 4,4,4
*/

// 3.2.c
#include<iostream>
#include<fstream>
#include<iomanip>
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
    if (number.empty()) {
        return false;
    }
    
    bool hasDecimal = false;
    int startPos = 0;
    
    if (number[0] == '-') {
        startPos = 1;
        if (number.length() == 1) {
            return false;
        }
    }
    
    for (int i = startPos; i < number.length(); i++) {
        if (number[i] == '.') {
            // If we already found a decimal point, return false
            if (hasDecimal) {
                return false;
            }
            hasDecimal = true;
        }
        // If it's not a number or decimal point, return false
        else if (number[i] < '0' || number[i] > '9') {
            return false;
        }
    }
    
    return true;

}

int main() {
    ifstream fin;
    ofstream log, summary;
    fin.open("coordinates2.txt");
    log.open("error_log.txt");
    summary.open("summary.txt");

    string line;
    const int num_of_items_in_line = 3;
    string arr[num_of_items_in_line] = {};
    double x_sum = 0, y_sum = 0, z_sum = 0;
    int line_counter = 0;

    while (getline(fin, line)){
        bool valid = true;
        split(line, ',',arr,num_of_items_in_line);
        for (int i = 0; i < num_of_items_in_line; ++i){
            if (!validateDouble(arr[i])){
                log << "Invalid entry: " << line << endl; //updated error logging
                valid = false;
            }
        }
        if (valid) {
            x_sum += stod(arr[0]);
            y_sum += stod(arr[1]);
            z_sum += stod(arr[2]);
            ++line_counter;
        }
    }
    if (line_counter > 0) {
        double x_avg = x_sum/line_counter;
        double y_avg = y_sum/line_counter;
        double z_avg = z_sum/line_counter;
        
        cout << "The center of mass is at:  " << x_avg << ", " << y_avg << ",  " << z_avg << "!";

        //updated summary
        summary << "Center of mass:" << endl;
        summary << "X: "<<  x_avg << endl;
        summary << "Y: "<<  y_avg << endl;
        summary << "Z: "<<  fixed << z_avg << endl;
        summary << "Number of valid entries: " << line_counter << endl;
        summary << "Process completed successfully!";
    } else {
        summary << "No valid coordinates processed!"; //catching for no valid lines
    }

    return 0;
}