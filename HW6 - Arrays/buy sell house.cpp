/*
find max profit acheived from buying and selling a house
*/
#include <iostream>
using namespace std;
int maxProfit(int prices[], const int NUM_MONTHS);

int main()
{
const int NUM_MONTHS = 5;
int prices[NUM_MONTHS] = {700000, 600000, 400000, 300000, 100000};
int profit = maxProfit(prices, NUM_MONTHS);
cout << "Maximum profit: " << profit << endl;
return 0;
}

//paste in after this line

int maxProfit(int prices[], const int NUM_MONTHS){
//get max item in array
//get min item in array AFTER max
//subtract min from max
    if (NUM_MONTHS<2){
        return 0;
    } else {
    int min = prices[0];
    int min_index = 0;
    int max = 0;

    for (int i = 1; i < NUM_MONTHS - 1; ++i){
        if (prices[i] < min){
            min = prices[i];
            min_index = i;
            max = prices[i+1];
        } 
    }
    for (int i = min_index+1; i < NUM_MONTHS; ++i){
        if (prices[i] > max) {
            max = prices[i];
        }
    }
    if (max - min <= 0) {
        return 0;
    }
    return max - min;
    }
}