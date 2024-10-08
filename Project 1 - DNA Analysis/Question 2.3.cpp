//no global vars
//no pass by reference
//all functions must match precisely
//well comment code
//create assert statements for each question to test the code

#include <cassert>

/*
- compare DNA strands & assess similarity
- for 2 equal length strands, similarity = (num of matches)/(length+1)
function: double strandSimilarity(string strand1, string strand2)
    - print nothing
    - return similarity by above
    - if strings are not the same length, return 0
    - assume it is always a valid strand
*/

#include <string>

double strandSimilarity(std::string strand1, std::string strand2);

int main() {
    assert(strandSimilarity("AGGT","CTGA") == .25);
    assert(strandSimilarity("CCTT","CCTT") == 1);
    assert(strandSimilarity("ATG","AAATTT") == 0);
    assert(strandSimilarity("CTGTAGAGCT" , "TAGCTACCAT") == .2);
    assert(strandSimilarity("GATCAG","GTTCAA") == 4.0/6.0);
    return 0;
}

double strandSimilarity(std::string strand1, std::string strand2){
    if (strand1.length() != strand2.length()) {
        return 0;
    }

    double match_counter = 0;
    //for every char in the strand, compare the two and increment the match counter if they are equal
    for (unsigned int i = 0;i < strand1.length();i++) {
        if (strand1[i] == strand2[i]){
            match_counter++;
        } 
    }
    //then simply divide the number of matching chars by the length of the strands
    return match_counter / strand1.length();
}

