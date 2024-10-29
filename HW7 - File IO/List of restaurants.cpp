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

struct Restaurant {
    string name;
    int food_quality;
    int cleanliness;
    int wait_time;
    double overall;
};

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

int readRestaurantDetails(string filename, Restaurant restaurant[], const int MAX_RESTAURANTS) {
    ifstream file_in(filename);

    // - If the file does not exist, -1 is returned.
    if (file_in.fail()) {
        return -1;
    }

    string line;
    int i = 0;
    while (getline(file_in,line)){
    // - If there is an incorrect number of attributes for a given line of the file, skip the line
        int count = 0;
        for (char c : line) {
            if (c == '~') {
                count += 1;
            }
        }
        if (count != 3) {
            continue;
        }

    // Read all the restaurant details from a given file and calculate the overall rating for all restaurants.
    const int arr_size = 4;
    string arr[arr_size];
    split(line, '~', arr, arr_size);
    restaurant[i].name = arr[0];
    restaurant[i].food_quality = stoi(arr[1]);
    restaurant[i].cleanliness = stoi(arr[2]);
    restaurant[i].wait_time = stoi(arr[3]);
    restaurant[i].overall = getOverallRating(restaurant[i]);

    ++i;
    }

    return i;
}

int getBest(Restaurant restaurants[], const int arr_size, string metric){
        if (arr_size <= 0) {
        return -1;
    }

    int best_index = 0;
    double best_value = -1;

    for (int i = 0; i < arr_size; i++) {
        double current_value;
        
        if (metric == "Food Quality") {
            current_value = restaurants[i].food_quality;
        }
        else if (metric == "Cleanliness") {
            current_value = restaurants[i].cleanliness;
        }
        else if (metric == "Wait Time") {
            current_value = restaurants[i].wait_time;
        }
        else if (metric == "Overall") {
            current_value = restaurants[i].overall;
        }
        else {
            return -1;  // Invalid metric
        }

        if (current_value > best_value) {
            best_value = current_value;
            best_index = i;
        }
    }

    return best_index;
}

int main(){
    Restaurant restaurants[30];
    int arr_size = readRestaurantDetails("restaurants_1.txt", restaurants, 30);

    // Checking if the file was opened correctly
    if (arr_size == -1){
        cout << "Failed to open file." << endl;
    }
    else if (arr_size == 0) {
        cout << "Empty file." << endl;
    }
    else{
        int idx = getBest(restaurants, arr_size, "Food Quality");
        if (idx == -1){
            cout << "Invalid metric." << endl;
        }
        else{
            cout << "Restaurant: " << restaurants[idx].name << " ";
            cout << "Ratings: ";
            cout << restaurants[idx].food_quality << " ";
            cout << restaurants[idx].cleanliness << " ";
            cout << restaurants[idx].wait_time << " ";
            cout << "Overall: ";
            cout << restaurants[idx].overall << " ";
            cout << endl;
        }
    }
}