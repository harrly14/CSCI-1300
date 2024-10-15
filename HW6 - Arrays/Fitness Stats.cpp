/*
- calculate sum of daily step counts 
- record running total in cumulative_steps array


*/
#include <iostream>
#include <iomanip>
using namespace std;
void stepCountCumulativeSum(int daily_steps[], const int NUM_DAYS, int cumulative_steps[]);
double stepCountDeviation(int daily_steps[], const int NUM_DAYS, const int OPTIMAL_STEP_COUNT);

int main()
{
const int NUM_DAYS = 5;
int daily_steps[NUM_DAYS] = {5000, 4000, 5000, 2000, 4000};
const int OPTIMAL_STEP_COUNT = 5000;
double deviation = stepCountDeviation(daily_steps, NUM_DAYS, OPTIMAL_STEP_COUNT);

// We are printing the deviation up to 3 decimal place

cout << fixed << setprecision(3) << deviation << endl;
return 0;
}

//only paste in code below

void stepCountCumulativeSum(int daily_steps[], const int NUM_DAYS, int cumulative_steps[]){

    //for each element in daily steps, starting at index 1
        //append the current element plus the previous element to cumulative steps
    cumulative_steps[0] = daily_steps[0];
    for (int i = 1; i < NUM_DAYS ; ++i){
        cumulative_steps[i] = daily_steps[i] + cumulative_steps[i-1];
    }

}

double stepCountDeviation(int daily_steps[], const int NUM_DAYS, const int OPTIMAL_STEP_COUNT){
    //calculate mean daily step count
    //return deviation (= mean - optimal step count)
    
    int total_steps = 0;
    for (int i = 0; i < NUM_DAYS; ++i){
        total_steps += daily_steps[i];
    }
    
    double mean = total_steps / NUM_DAYS;

    return mean - OPTIMAL_STEP_COUNT;
}
