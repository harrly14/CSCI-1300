<<<<<<< HEAD
#include <iostream>
#include <string>

using namespace std;

int main(){
    string user_input;   // create a string "user_input"
    
    getline(cin, user_input); //uses cin to get the user input and make the variable equal to it.
    // we could use "cin >> user_input;", but this will only get the first word that the user inputs, not the whole string. 
    cout << user_input; //print the updated string using cout
    return 0;
=======
#include <iostream>
#include <string>

using namespace std;

int main(){
    string user_input;   // create a string "user_input"
    
    getline(cin, user_input); //uses cin to get the user input and make the variable equal to it.
    // we could use "cin >> user_input;", but this will only get the first word that the user inputs, not the whole string. 
    cout << user_input; //print the updated string using cout
    return 0;
>>>>>>> 6c2cf93a5ffcc7c8cdeb3eac2fcaa8177f3ec084
}