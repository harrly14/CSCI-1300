/*
Create two integer arrays set1 and set2 in the main(). The length of set1 and set2 should be 5 and 2,
respectively. Prompt the user to enter 5 integers that go into set1. Do the same with 2 integers for set2.
Then use the arrays to print all the possible pairs of the elements in set1 with the elements in set2.

Sample Run 3.2.1
Please enter 5 integers for the first set:
input: 1 2 3 4 5
Please enter 2 integers for the second set:
input: 10 20
1-10 1-20
2-10 2-20
3-10 3-20
4-10 4-20
5-10 5-20

*/

/*3.2.a
print "Please enter 5 integers for the first set:"
get the users input with a space delimiter, put those inputs into an array of size 5
validate input somehow
print "Please enter 2 integers for the second set:"
get the users input with a space delimiter, put them into a second array with size 2
validate input somehow
for i in set1
    for j in set2
        print set1[i] - set[j]
*/

/*
3.2.b. Pick possible inputs for your program. Choose as many inputs as you think you need to
thoroughly test your program. Follow the steps you wrote for these values to find your result, and verify it.

case 1: 
input for set1: 1 2 3 4 5
input for set2: 10 20
output: 1-10 1-20
2-10 2-20
3-10 3-20
4-10 4-20
5-10 5-20

case 2: 
input for set1: 1,2 3 4 5
invalid input
(reprompt)
input for set2: 10, 20

*/
#include <iostream>
using namespace std;
int main() {
    //note that this code simply cuts off any additional integers put in if you put in too many. it does not tell you. 
    int set1[5] = {};
    int set2[2] = {};
    cout <<  "Please enter 5 integers for the first set:" << endl;
    //get the users input with a space delimiter, put those inputs into an array of size 5
    for (int i = 0; i < 5;i++){
        cin >> set1[i];
    }

    cin.clear(); //clear any erros in cin
    cin.ignore(100, '\n'); //removes up to 100 characters from the buffer

    cout << "Please enter 2 integers for the second set:" << endl;
    for (int i = 0; i < 2; i++){
        cin >> set2[i];
    }

    for (int i = 0; i < 5; i++){
        cout << set1[i] << "-" << set2[0] << " " << set1[i] << "-" << set2[1] << endl;
    }

}