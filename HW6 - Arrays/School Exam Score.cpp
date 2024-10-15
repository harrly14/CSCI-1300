#include <iostream>
using namespace std;
int minAverg(int scores[][10], const int NUM_STUDENTS, double threshold);

int main()
{
    int scores[2][10] = {
    {80, 90, 85, 95, 88, 82, 75, 89, 91, 87},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    };
    cout << "returned student index: " << minAverg(scores, 2, 10.0);
    return 0;
}

/*
- return index of student whose average score is les than or equal to the threshold
- return -1 if there is not average score that is less than or equal to threshold
- assume array is non-empty
*/

int minAverg(int scores[][10], const int NUM_STUDENTS, double threshold){

    for (int i = 0; i < NUM_STUDENTS; ++i){
        int score_total = 0;
        for (int j = 0; j < 10; ++j) {
            score_total += scores[i][j];
        }
        if (score_total / 10 <= threshold){
            return i;
        } 
    }
    return -1;
}