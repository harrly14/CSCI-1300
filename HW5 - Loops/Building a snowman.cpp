/*calculate the amount of time each snowman snowball will roll to reach required size.
calculate for head, midbody, lower body, and total time needed for all 3. 
each snowball starts at 1 unit/sec, and increases by 1 unit each sec

check if size input is pos in main. if non-pos, output "Please enter a positive integer for <section> size:" + prompt for input again
*/
#include <iostream>
#include <vector>
using namespace std;

int calculateTime(int target_size){
    int acc, size,seconds;
    size = 1;
    acc = 0;
    seconds = 0;
    while (size<target_size) {
        acc++;
        seconds++;
        size+=acc;
    }
    return seconds;
}

int main() {
    int ts1, ts2, ts3;
    cout << "Enter head size:" << endl;
    cin >> ts1;

    while (ts1<=0) {
        cout << "Please enter a positive integer for head size:" << endl;
        cin >> ts1;
    }

    cout << "Enter mid-body size:" << endl;
    cin >> ts2;
    
    while (ts2<=0) {
        cout << "Please enter a positive integer for mid-body size:" << endl;
        cin >> ts2;
    }

    cout << "Enter lower-body size:" << endl;
    cin >> ts3;
    
    while (ts3<=0) {
        cout << "Please enter a positive integer for lower-body size:" << endl;
        cin >> ts3;
    }

    cout << "Time to reach head size: " << calculateTime(ts1) << " seconds" << endl;
    cout << "Time to reach mid-body size: " << calculateTime(ts2) << " seconds" << endl;
    cout << "Time to reach lower-body size: " << calculateTime(ts3) << " seconds" << endl;
    cout << "Total time to create the snowman: " << calculateTime(ts1)+calculateTime(ts2)+calculateTime(ts3)<<" seconds" << endl;
    return 0;
}