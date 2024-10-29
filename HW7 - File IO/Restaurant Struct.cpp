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

struct Restaurant {
    string name;
    int food_quality;
    int cleanliness;
    int wait_time;
    double overall;
};

//- If any of the ratings in restaurant are not within its bound, return
//-1. The rating bounds are: food quality (0-10), cleanliness (0-10), wait time (0-5)
// Overall Rating = 0.5 × food quality + 0.3 × cleanliness + 0.2 × wait time
double getOverallRating(Restaurant restaurant){
    if (restaurant.food_quality < 0 || restaurant.food_quality > 10) {
        return -1;
    }  
    if (restaurant.cleanliness < 0 || restaurant.cleanliness > 10) {
        return -1;
    }
    if (restaurant.wait_time < 0 || restaurant.wait_time > 5) {
        return -1;
    }

    return (.5*restaurant.food_quality) + (.3*restaurant.cleanliness) + (.2*restaurant.wait_time);
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