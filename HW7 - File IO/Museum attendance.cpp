/*
Given two attendance sheets, the function will compare and print out
any individuals who are present in the first sheet but missing in the
second

string first_attendance_file - The first attendance sheet.
string second_attendance_file - The second attendance sheet.

- If either file does not exist, print “Failed to open attendance files”.
- If a name exists in the second_attendance_file, it will also be present
in the first_attendance_file. In other words, no new names are added
to the second_attendance_file that were not in the first.
- Hint: The largest file has 24 names; therefore, declare your array with
size 30 to ensure it accommodates all test cases.

Inputs: Example_3.txt:
Anya Garcia
Oliver Jones
Sofia Smith

Example_4.txt:
Anya Garcia
Sofia Smith
Oliver Jones

Output:
Every student has boarded the bus. It's time to leave.
*/
#include <iostream>
#include <fstream>
using namespace std;

void compareAttendanceSheet(string first_attendance_file, string second_attendance_file){
    ifstream attendance1(first_attendance_file), attendance2(second_attendance_file);
    
    if (attendance1.fail() || attendance2.fail()) {
        cout << "Failed to open attendance files" << endl;
        return;   
    }

    const int arr_size = 30;
    string arr[arr_size];
    
    //for each line in att2
        //compare line to all lines in att1
        //if we find the lines to be the same, continue
        //if we get to the end and lines are never the same, add that name to the array

    string att2_line, att1_line;
    int counter = 0;

    while (getline(attendance1, att1_line)) {
        bool found = false;

        while(getline(attendance2, att2_line)) {
            if (att1_line==att2_line){
                found = true;
                break;
            }
        }
        if (!found){
            arr[counter] = att1_line;
            ++counter;
        }
        attendance2.clear();
        attendance2.seekg(0);
    }
    if (counter == 0) {
        cout << "Every student has boarded the bus. It's time to leave.";
    } else {
            cout << "Students yet to board the bus are" << endl;
        for (int i = 0; i < counter; ++i){
            cout << arr[i] << endl;
        }
    }

}

int main() {
    compareAttendanceSheet("attendance_sheet_1.txt", "attendance_sheet_2.txt");
    return 0;
}