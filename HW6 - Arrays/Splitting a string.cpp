/*
- return an int, the number of pieces the input text is split into
- populate arr[] with the elements
- return 1 if delim is not found. place entire string as first element
- return -1 if string is split into more pieces than the size of the array
    - fill array with as many pieces as possible
- return 0 if the string is empty
*/
#include <iostream>
using namespace std;

int split(string input_string, char separator, string arr[], const int ARR_SIZE);

void printArray(string arr[], const int NUM_ELEMENTS){
    for (int i=0; i < NUM_ELEMENTS; i++) {
        cout << "arr["<< i << "]:" << arr[i] << endl;
    }
}

int main() {
    string testcase = "Bangkok,Berlin,Birmingham,Bogota,Busan,Baton Rouge,Beaumont,Boise,Budapest";
    char separator = ',';
    const int ARR_SIZE = 5;
    string arr[ARR_SIZE];
    // num_splits is the value returned by split
    int num_splits = split(testcase, separator, arr, ARR_SIZE);
    cout << "Function returned value: " << num_splits << endl;
    // print array contents
    printArray(arr, ARR_SIZE);
}



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
