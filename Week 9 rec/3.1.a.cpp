#include <iostream>
#include <string>
using namespace std;
void flipSign(int numbers[], int length){ //edited function to include length of array
    for (int i = 0; i < length; i++){ //edited for loop to stop at the end of the array
        numbers[i] = -1.0 * numbers[i];
    }
    return;
}

int main(){
    const int length = 4;
    int numbers[] = {1, 2, 3, 4};
    cout << "The contents of the array before changing: ";

    for (int i = 0; i < length; i++){
        cout << numbers[i] << " ";
    }
    
    cout << endl;
    flipSign(numbers, length);
    cout << "The contents of the array after changing: ";

    for (int i = 0; i < length; i++){
        cout << numbers[i] << " ";
    }
    return 0;
}