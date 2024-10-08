//no global vars
//no pass by reference
//all functions must match precisely
//well comment code
//create assert statements for each question to test the code

#include <cassert>

/*
- find best similarity between two DNA strands
- print best similarity score
- input_strand length >= target stand length
- slide target strand across input strand to find best match
- if params are valid, return an int representing the starting 
index for the best match
- and print "Best similarity score: " {score}
- if input strand length <=target strand length
    - return -1
    - print "Best similarity score: 0.0"
- make use of strandsimilarity function
- assume input is valid
*/

#include <iostream>


double strandSimilarity(std::string strand1, std::string strand2);
int bestStrandMatch(std::string input_strand, std::string target_strand);

int main() {
    assert(bestStrandMatch("GATCAGT","TCA") == 2);
    assert(bestStrandMatch("AACCTGAC","ACT") == 1);
    assert(bestStrandMatch("CTG","CCCC") == -1);
    assert(bestStrandMatch("ATCGTA","TTCGAT") == 0);
    assert(bestStrandMatch("AAAAA","CCCCC") == 0);
    return 0;
}

double strandSimilarity(std::string strand1, std::string strand2){
    if (strand1.length() != strand2.length()) {
        return 0;
    }

    double match_counter = 0;
    for (unsigned int i = 0;i < strand1.length();i++) {
        if (strand1[i] == strand2[i]){
            match_counter++;
        } 
    }
    return match_counter / strand1.length();
}

int bestStrandMatch(std::string input_strand, std::string target_strand){
    std::string strand1;
    
    if (input_strand.length() < target_strand.length()){
        std::cout<<"Best similarity score: 0.0"<<std::endl;
        return -1;
    }

    double best_similarity_score = 0.0;
    int best_match_index = 0;

    //repeats a number of times equal to the difference between strand lengths
    for (unsigned int i = 0; i <= input_strand.length()-target_strand.length(); i++){
        //make a substrand of the input strand that is as long as the target strand and the starting index increases by 1 with each loop
        //this is the strand that we compare the target strand to
        std::string current_substrand = input_strand.substr(i,target_strand.length());

        //compare the target strand and the substrand we made
        double current_similarity = strandSimilarity(current_substrand,target_strand);

        //maximize the 
        if (current_similarity > best_similarity_score){
        best_similarity_score = current_similarity;
        best_match_index = i;
        }
    }
    std::cout <<"Best similarity score: "<<best_similarity_score<<std::endl;
    return best_match_index;
}