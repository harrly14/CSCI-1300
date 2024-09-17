#include <iostream> //"include" indicates a header for a required service. 
//iostream allows output to be display and input to be read. 

using namespace std; //all variables and objects exist within a namespace. 
//std is iostream's namespace. without this line, you would have to type std:: before every var, obj, function, etc.

int main() { //initialize the main function
    cout  << "Hello, world! Hello CSCI 1300" << endl; //cout prints to the terminal. it is within the iostream header file. 
    // << indicates the data you are printing using cout. "<< endl" indicates another argument that declares we are ending the line
    return 0; //best practice to return 0 at the end of your code. indicates that the program has ended with no problems.
}

// if you change the code, make sure to recompile with "g++ [filename]" and then rerun with ".\a.exe" 
// "g++ [filename]" compiles the code and ".\a.exe" runs the compiled code which is created in the parent folder of the code
// compiler flag: can specify the version of cpp to use. flag: "-std=c++17"
// compiler flag: can specify the name of the output file. flag: "-o [filename]"