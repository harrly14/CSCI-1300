//no global vars
//no pass by reference
//all functions must match precisely
//well comment code
//create assert statements for each question to test the code

#include <cassert>

/*
function: void reverseComplement(string strand)
    - find the compliment of each base
    - reverse the string
    - a & t
    - c & g
    - print to console
    assume strand is valid
*/
#include <iostream>

void reverseComplement(std::string strand);

int main() {
    reverseComplement("ATCGTACG");
    reverseComplement("AAACCC");
    reverseComplement("AGCT");
    reverseComplement("A");
    return 0;
}



void reverseComplement(std::string strand) {
    std::string reverse_complement;

    for (unsigned int i = 0; i < strand.length(); i++) {
        //for every base in the strand, add the reverse base to the FRONT of the new string, so that it is reversed
        switch (strand[i])
        {
        case 'A':
            reverse_complement = 'T' + reverse_complement;
            break;
        case 'T':
            reverse_complement = 'A' + reverse_complement;
            break;
        case 'C':
            reverse_complement = 'G' + reverse_complement;
            break;
        case 'G':
            reverse_complement = 'C' + reverse_complement;
            break;
        }
    }


    std::cout << reverse_complement << std::endl;
}