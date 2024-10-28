/*
Given a text file that contains information on the trails, the function
will print the following:
- Number of valid lines read from the file. A valid line must contain
exactly three fields: the hike name, length (as an integer), and elevation
gain (as an integer).
- Name and the length of the longest hike.
- Name and the length of the shortest hike.
- Name and elevation gain per mile of the steepest hike. Th

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
using namespace std;

void printHikeStats(string file_name){

}

int main() {
    printHikeStats("long_hikes.txt");
    return 0;
}