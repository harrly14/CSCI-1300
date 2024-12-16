//no global vars
//no pass by reference
//all functions must match precisely
//well comment code
//create assert statements for each question to test the code

#include <cassert>

/*
- check if a string contains only valid DNA bases
function: bool isValidStrand(string strand)
    - return true if string is a valid DNA strand
    - return false otherwise
    - print nothing
    - if string is empty, return false
*/
#include <string>

bool isValidBase(char base);
bool isValidStrand(std::string strand);

int main() {
    assert(isValidStrand("ATGCTTCAA") == true);
    assert(isValidStrand("CATCG") == true);

    assert(isValidStrand("CTTZ") == false);
    assert(isValidStrand("") == false);
    assert(isValidStrand("CAT TAC") == false);
    assert(isValidStrand("0") == false);
    assert(isValidStrand("aCAT") == false);
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

bool isValidStrand(std::string strand){
    //not valid if string is empry
    if (strand.length() == 0){
        return false;
    }

    //for every char in string, run the valid bases function
    for (char c : strand){
        //if isValidBase is ever false, return false
        if (isValidBase(c) == false){
            return false;
        }
    }
    // only executes if no bases return false
    return true;
}