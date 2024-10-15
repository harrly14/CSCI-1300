#include <iostream>
#include <string>
using namespace std;

int main(){
    const int N = 6;
    string animals[N] = {"lion", "cat", "bear", "dog", "elephant", "fox"};
    for (int i = 0; i < N; i++){
        if (animals[i].length() == 4){ //changed from animals.length()[i] to animals[i].length()
            cout << animals[i] << endl;
        }
    }
    return 0;
}