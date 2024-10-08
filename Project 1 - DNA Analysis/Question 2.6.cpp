//no global vars
//no pass by reference
//all functions must match precisely
//well comment code
//create assert statements for each question to test the code

#include <cassert>

/*
function void transcribeDNAtoRNA(string strand)
    - transcribe DNA to RNA
    - print RNA sequence to console
    - Replace all "T"s with "U"
    - assume valid DNA strand
*/
#include <iostream>

void transcribeDNAtoRNA(std::string strand);

int main() {
    transcribeDNAtoRNA("ATCGTACG");
    return 0;
}

void transcribeDNAtoRNA(std::string strand){
    std::string RNA_strand = "";
    //append each char from the strand to the RNA strand, unless it is a T, in which case you have to append U.
    for (char c : strand) {
        if (c == 'T') {
            RNA_strand += 'U';
        } else {
            RNA_strand += c;
        }
    }
    std::cout << RNA_strand;

}