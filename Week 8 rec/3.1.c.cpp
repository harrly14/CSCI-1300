#include <iostream>
using namespace std;
int main(){
    int N = 4; //changed from 3 to 4
    string item[N] = {"book", "pen", "pencil", "eraser"}; //changed item[] to item[N]. changed from char to string
    //printing all the items
    for (int i = 0; i < N; i++){
        cout << "The item list has " << item[i] << endl; //changed from items[j] to item[i]
    }
    return 0;
}