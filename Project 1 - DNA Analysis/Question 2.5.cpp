//no global vars
//no pass by reference
//all functions must match precisely
//well comment code
//create assert statements for each question to test the code

#include <cassert>

/*
- compare two DNA sequences and identify all types of mutations
- align sequences based on best match and then process sequences
- print out mutations as they are detected
- mutations: 
    - substitution: bases at same position differ
    - insertion: an extra base is present in target
    - deletion: a base from input is missing in target

- determine longest of the stands, then use bestmatch() to align them
- then, print best alignment index
- compare sequences char by char to identify mutations
function: void identifyMutations(string input_strand, string target_strand)
    - assume both are valid
    - if no mutations: output "No mutations found."
*/

#include <iostream>


double strandSimilarity(std::string strand1, std::string strand2);
int bestStrandMatch(std::string input_strand, std::string target_strand);
void identifyMutations(std::string input_strand, std::string target_strand);

int main() {
    identifyMutations("TGC", "TGCAGT");
    identifyMutations("CGGCTATCGTAG", "CGTAG");
    identifyMutations("GATCAGT","GTTCAG");
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

    for (unsigned int i = 0; i <= input_strand.length()-target_strand.length(); i++){
        std::string current_substrand = input_strand.substr(i,target_strand.length());
        double current_similarity = strandSimilarity(current_substrand,target_strand);

        if (current_similarity > best_similarity_score){
        best_similarity_score = current_similarity;
        best_match_index = i;
        }
    }
    std::cout <<"Best similarity score: "<<best_similarity_score<<std::endl;
    return best_match_index;
}

void identifyMutations(std::string input_strand, std::string target_strand) {

    //if the strings are the same, you can give the values right away
    if(input_strand == target_strand) {
        std::cout << "Best similarity score: 1" << std::endl << "Best alignment index: 0" << std::endl << "No mutations found." << std::endl;
        return;
    }

    unsigned int best_match_index;
    
    //if the input strand is shorter than target strand, you have to call the bestStrandMatch function backwards
    //then, in both these loops, in puts the bestStrandMatch value into the best_match_index 
    //after that, add 0's so that the shorter string becomes the length of the longer string, and the best match sections match up
    //i.e. entering "TGC", "TGCAGT" as the params turns them into "0TGC000", "ATGCAGT"
    if (input_strand.length() < target_strand.length()) {

        best_match_index = bestStrandMatch(target_strand,input_strand);

        //adds 0's to shorter string as stated above
        for (unsigned int i = 0; i < target_strand.length(); i++) {
            if (i < best_match_index) {
                input_strand = '0' + input_strand;
            } else if (i >= input_strand.length()) {
                input_strand = input_strand + '0';
            }
        }

    } else if (input_strand.length() >= target_strand.length()) {
        best_match_index = bestStrandMatch(input_strand,target_strand);

        //adds 0's to shorter string as stated above
        for (unsigned int i = 0; i < input_strand.length(); i++) {
            if (i < best_match_index) {
                target_strand = '0' + target_strand;
            } else if (i >= target_strand.length()) {
                target_strand = target_strand + '0';
            }
        }
    }

    std::cout << "Best alignment index: " << best_match_index << std::endl;

    //find where the strands are not the same
    //its a deletion if there is a valid base in the input_strand, but not the target_strand
    //its a deletion if there is a valid base in the target_strand, but not the input_strand
    //its a substitution if there is a valid base in both strands, but they are not the same
    for (unsigned int i = 0; i < target_strand.length(); i++) {
        if (input_strand[i] != target_strand[i]){
            if (target_strand[i] == '0') {
                std::cout << "Deletion at position " << i + 1 << ": " << input_strand[i] << " is deleted in target strand" << std::endl;
            } else if (input_strand[i] == '0'){
                std::cout << "Insertion at position " << i + 1 << ": " << target_strand[i] << " is inserted in target strand" << std::endl;
            } else if (input_strand[i] != '0' && target_strand[i] != '0'){
                std::cout << "Substitution at position " << i + 1 << ": "  << input_strand[i] << " -> " << target_strand[i] << std::endl;
            }
        }
    }
}

