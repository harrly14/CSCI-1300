/*
Given a text file that contains information on the trails, the function
will print the following:
- Number of valid lines read from the file. A valid line must contain
exactly three fields: the hike name, length (as an integer), and elevation
gain (as an integer).
- Name and the length of the longest hike.
- Name and the length of the shortest hike.
- Name and elevation gain per mile of the steepest hike.  This number should be rounded to one decimal point (use setprecision).

- If the file does not exist, print “Could not open file.”
- If there is a tie, choose the first one

Content of hikes_blanks1.txt:
The South West Coast Path|630|115000
Continental Divide Trail|3100|457000
Great Himalayan Trail|1056|289000

Input:
hikes_blanks1.txt

Output:
Longest hike: Continental Divide Trail at 3100 miles.
Shortest hike: The South West Coast Path at 630 miles.
Steepest hike: Great Himalayan Trail at 273.7 feet gained per mile.

*/
#include <iostream>
#include <fstream>
#include <iomanip>
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

void printHikeStats(string file_name){
    ifstream file_in(file_name);
    string line;

    //- If the file does not exist, print “Could not open file.”
    if (file_in.fail()) {
        cout << "Could not open file.";
        return;
    }

    int longest_length = 0;
    int longest_index, shortest_index;
    int shortest_length = 10000000;
    int num_of_lines = 0;
    double steepest_elev = 0;
    int steepest_index;
    int i = 0;
    const int num_of_atrs = 3;
    string arr[15][num_of_atrs];

    while(getline(file_in, line)) {


        int counter = 0;
        for (char c : line) {
            if (c == '|') {
                ++counter;
            }
        }
        if (counter != 2) {
            continue;
        }

        ++num_of_lines;

        split(line, '|', arr[i], num_of_atrs);
        

        if (stoi(arr[i][1]) > longest_length) {
            longest_length = stoi(arr[i][1]);
            longest_index = i;
        } 
        if (stoi(arr[i][1]) < shortest_length){
            shortest_length = stoi(arr[i][1]);
            shortest_index = i;
        }
        if (stod(arr[i][2])/stod(arr[i][1]) > steepest_elev) {
            steepest_elev = stod(arr[i][2])/stod(arr[i][1]);
            steepest_index = i;
        }
        ++i;
    }
    cout << "Number of lines read: " << num_of_lines << "." << endl;
    cout << "Longest hike: " << arr[longest_index][0] << " at " << arr[longest_index][1] << " miles." << endl;
    cout << "Shortest hike: " << arr[shortest_index][0] << " at " << arr[shortest_index][1] << " miles." << endl;
    cout << "Steepest hike: " << arr[steepest_index][0] << " at " << setprecision(1) << fixed << steepest_elev << " feet gained per mile." << endl;
}

int main() {
    printHikeStats("long_hikes.txt");
    return 0;
}