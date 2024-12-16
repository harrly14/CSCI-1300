//no global vars
//no pass by reference
//all functions must match precisely
//well comment code
//create assert statements for each question to test the code

#include <cassert>

/*
- check whether data is valid or corrupted
- check the sequences only consist of A,C,B, and T.
function: bool isValidBase(char base)
    - determine whether given character is a valid DNA base. 
    - dont print anything
    - return true if the character is a valid base
    - case-sensitive
*/

bool isValidBase(char base);

int main() {
    //test valid bases
    assert(isValidBase('A') == true);
    assert(isValidBase('C') == true);
    assert(isValidBase('G') == true);
    assert(isValidBase('T') == true);
    //test invalid alphabet inputs
    assert(isValidBase('a') == false);
    assert(isValidBase('c') == false);
    assert(isValidBase('g') == false);
    assert(isValidBase('t') == false);
    assert(isValidBase('Y') == false);
    //test non-alphabet inputs
    assert(isValidBase(' ') == false);
    assert(isValidBase('0') == false);
    return 0;
}

bool isValidBase(char base){
    switch(base){
        //if A,C,G, or T return true
        case 'A':
        case 'C':
        case 'G':
        case 'T':
            return true;
        //return false for everything else
        default:
            return false;
    }
}