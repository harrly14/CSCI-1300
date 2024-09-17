#include <iostream>
#include <string>


using namespace std;

int main(){
    //divide 200 seconds into minutes and seconds
    int seconds = 200;
    int secs_in_mins = seconds/60;
    int remainder_of_secs = seconds % 60;
    cout<<seconds<<" seconds is equal to "<<secs_in_mins<<" minutes and "<<remainder_of_secs<<" seconds"<<endl;
    return 0;
}
