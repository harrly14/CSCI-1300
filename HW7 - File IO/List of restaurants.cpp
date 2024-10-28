/*
Read all the restaurant details from a given file and calculate the overall
rating for all restaurants.

- If the file does not exist, -1 is returned.
- If there is an incorrect number of attributes for a given line of the file,
skip the line

Restaurant: Wendys Ratings: 6 3 2 Overall: 4.3
Restaurant: Chick-fil-a Ratings: 9 5 5 Overall: 7
Restaurant: Snarfburger Ratings: 10 4 3 Overall: 6.8
Restaurant: Cosmo’s Pizza Ratings: 7 3 2 Overall: 4.8
---
There is a part B as well
*/
#include <iostream>
#include <fstream>
using namespace std;

int readRestaurantDetails(string filename, Restaurant restaurant[], const int MAX_RESTAURANTS) {

}

int main()
{
    Restaurant restaurants[30];
    int res_size = readRestaurantDetails("restaurants.txt", restaurants, 30);

    // Checking if the file was opened correctly
    if (res_size == -1){
        cout << "Failed to open file." << endl;
    }
    else {
        for (int i = 0; i < res_size; ++i) {
            cout << "Restaurant: " << restaurants[i].name << " ";
            cout << "Ratings: ";
            cout << restaurants[i].food_quality << " ";
            cout << restaurants[i].cleanliness<< " ";
            cout << restaurants[i].wait_time << " ";
            cout << "Overall: ";
            cout << restaurants[i].overall << " ";
            cout << endl;
        }
    }
}