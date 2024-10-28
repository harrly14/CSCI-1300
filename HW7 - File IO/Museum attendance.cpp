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

}

int main() {
    compareAttendanceSheet("example_1.txt", "example_2.txt");
    return 0;
}