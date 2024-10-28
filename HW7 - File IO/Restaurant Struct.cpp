/*
Given a object of type Restaurant, calculate its overall rating.

- If any of the ratings in restaurant are not within its bound, return
-1. The rating bounds are: food quality (0-10), cleanliness (0-10), wait
time (0-5)


The sample inputs will be given in the order of name, food quality, cleanliness, and wait
time, respectively.
Input:
Aloy Thai
9
8
3

Output:
Restaurant: Aloy Thai Overall: 6.8
*/
#include <iostream>
#include <fstream>
using namespace std;

double getOverallRating(Restaurant restaurant){

}

int main() {
    Restaurant r;
    r.name = "McDonalds";
    r.food_quality = 4;
    r.cleanliness = 7;
    r.wait_time = 5;
    r.overall = getOverallRating(r);
    if(r.overall == -1)
    {
    cout << "Invalid rating(s) entered." << endl;
    }
    else
    {
    cout << "Restaurant: " << r.name << " Overall: " << r.overall << endl;
    }
    return 0;
}