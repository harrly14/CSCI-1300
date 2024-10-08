//no global vars
//no pass by reference
//all functions must match precisely
//well comment code
//create assert statements for each question to test the code

#include <cassert>

/*
- create a main function that allows user to interact with previously written functions
1. present menu:
--- DNA Analysis Menu ---
    1. Calculate the similarity between two sequences of the same length
    2. Calculate the best similarity between two sequences of either equal or unequal length
    3. Identify mutations
    4. Transcribe DNA to RNA
    5. Find the complement of a DNA sequence
    6. Extract reading frames
    7. Exit

    - run on a loop, offering options until they choose to exit
- account for bad user input. if bad, print "Invalid input. Please 
enter a valid sequence." until they enter a valid sequence
- functions that must have strings of the same length should be validated
    - if not same size, print "Error: Input strands must be of the same length."
and return to the menu
*/
#include <iostream>

double strandSimilarity(std::string strand1, std::string strand2){
    if (strand1.length() != strand2.length()) {
        //edited from the question so that you don't get an error when you shouldn't 
        //(previously was return -1)
        return -1;
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

        //maximize the similarity 
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

void getCodingFrames(std::string strand) {
    //if AGC is not in the strand OR if there is no stop codon, there are no ORFs
    if (strand.find("ATG") == std::string::npos) {
        std::cout << "No reading frames found." << std::endl;
        return;
    } else if (strand.find("TAG") == std::string::npos && 
               strand.find("TAA") == std::string::npos && 
               strand.find("TGA") == std::string::npos ) {
        std::cout << "No reading frames found." << std::endl;
        return;
    }
    
    int starting_index = 0;
    int num_of_orfs_found = 0;
    
    //while you can find the start codon in the string, perform the below
    //this stops at a certain point because each time we perform the loop, we set the starting_index to 1+the last start codon
    //therefore, it will search for a start codon starting just after the previous start codon
    while (strand.find("ATG", starting_index) != std::string::npos) {
        //the logic i was talking about above. we will use this starting index to create a substring that will become our ORF
        starting_index = strand.find("ATG", starting_index);
        //useful for determining if we found any ORFs
        bool stop_codon_found = false;
        
        //starts at the starting index because we dont care about anything before the start codon
        //ends at strand length - 3 because we are checking each group of 3 chars, so you dont need to check the last 2 chars
        for (unsigned int i = starting_index; i <= strand.length()-3; i+=3) {

            std::string current_codon = strand.substr(i,3);

            //if the codon we are checking is a stop codon
            if (current_codon == "TAG" || current_codon == "TGA" || current_codon == "TAA") {

                //index is i + 3 because we want to use the end of the codon, not the start
                unsigned int stop_codon_index = i + 3;
                //the ORF is from the start index to the stop index
                std::string ORF = strand.substr(starting_index, stop_codon_index-starting_index);
                std::cout << ORF << std::endl;
                
                num_of_orfs_found += 1;
                //setting it to stop codon index because we want to check for start codons starting at where the previous ORF stopped
                starting_index = stop_codon_index;
                stop_codon_found = true;
                break;
            }
        }
        
        // If no stop codon was found, increment starting_index to avoid infinite loop
        if (!stop_codon_found) {
            starting_index++;
        }
    }
    //if we did not find any ORFs, print no ORFs found
    if (num_of_orfs_found < 1) {
        std::cout << "No reading frames found." << std::endl;
    }
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

int main() {
    //setting the selection to something invalid so the loop prompts
    int selection = 10;

    while (selection != 7) {
        //I know I can do this all in one line, but this is easier to read
        std::cout << "--- DNA Analysis Menu ---" << std::endl;
        std::cout <<"1. Calculate the similarity between two sequences of the same length" << std::endl;
        std::cout << "2. Calculate the best similarity between two sequences of either equal or unequal length" << std::endl;
        std::cout << "3. Identify mutations" << std::endl;
        std::cout << "4. Transcribe DNA to RNA" << std::endl;
        std::cout << "5. Find the reverse complement of a DNA sequence" << std::endl;
        std::cout << "6. Extract coding frames" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Please enter your choice (1 - 7):" << std::endl;
        std::cin >> selection;

        std::string strand1, strand2;

        switch (selection)
        //need input validation for each one
        {
        case 1:
            std::cout << "Enter the first DNA sequence:" << std::endl;
            std::cin >> strand1;

            //input validation
            while (!isValidStrand(strand1)) {
                std::cout << "Invalid input. Please enter a valid sequence." << std::endl << "Enter the first DNA sequence:" << std::endl;
                std::cin >> strand1;
            }
            std::cout << "Enter the second DNA sequence:" << std::endl;
            std::cin >> strand2;

            //input validation
            while (!isValidStrand(strand2)) {
                std::cout << "Invalid input. Please enter a valid sequence." << std::endl << "Enter the second DNA sequence:" << std::endl;
                std::cin >> strand2;
            }

            //error handling
            if (strandSimilarity(strand1,strand2) == -1) {
                std::cout << "Error: Input strands must be of the same length." << std::endl;
            } 
            else {
                std::cout << "Similarity score: " << strandSimilarity(strand1,strand2) << std::endl;
            }

            break;
        case 2:
            std::cout << "Enter the first DNA sequence:" << std::endl;
            std::cin >> strand1;

            //input validation
            while (!isValidStrand(strand1)){
                std::cout << "Invalid input. Please enter a valid sequence." << std::endl << "Enter the first DNA sequence:" << std::endl;
                std::cin >> strand1;
            }

            std::cout << "Enter the second DNA sequence:" << std::endl;
            std::cin >> strand2;

            //input validation
            while (!isValidStrand(strand2)){
                std::cout << "Invalid input. Please enter a valid sequence." << std::endl << "Enter the second DNA sequence:" << std::endl;
                std::cin >> strand2;
            }

            bestStrandMatch(strand1,strand2);

            break;
        case 3:
            std::cout << "Enter the first DNA sequence:" << std::endl;
            std::cin >> strand1;

            //input validation
            while (!isValidStrand(strand1)){
                std::cout << "Invalid input. Please enter a valid sequence." << std::endl << "Enter the first DNA sequence:" << std::endl;
                std::cin >> strand1;
            }

            std::cout << "Enter the second DNA sequence:" << std::endl;
            std::cin >> strand2;

            //input validation
            while (!isValidStrand(strand2)){
                std::cout << "Invalid input. Please enter a valid sequence." << std::endl << "Enter the second DNA sequence:" << std::endl;
                std::cin >> strand2;
            }

            identifyMutations(strand1,strand2);

            break;
        case 4:
            std::cout << "Enter the DNA sequence to be transcribed:" << std::endl;
            std::cin >> strand1;

            //input validation
            while (!isValidStrand(strand1)){
                std::cout << "Invalid input. Please enter a valid sequence." << std::endl << "Enter the DNA sequence to be transcribed:" << std::endl;
                std::cin >> strand1;
            }

            std::cout << "The transcribed DNA is: ";
            transcribeDNAtoRNA(strand1);
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "Enter the DNA sequence:" << std::endl;
            std::cin >> strand1;

            //input validation
            while (!isValidStrand(strand1)){
                std::cout << "Invalid input. Please enter a valid sequence." << std::endl << "Enter the DNA sequence:" << std::endl;
                std::cin >> strand1;
            }

            std::cout << "The reverse complement is: ";
            reverseComplement(strand1);
            break;
        case 6:
            std::cout << "Enter the DNA sequence:" << std::endl;
            std::cin >> strand1;

            //input validation
            while (!isValidStrand(strand1)){
                std::cout << "Invalid input. Please enter a valid sequence." << std::endl << "Enter the DNA sequence:" << std::endl;
                std::cin >> strand1;
            }

            std::cout << "The extracted reading frames are: " << std::endl;
            getCodingFrames(strand1);
            
            break;
        case 7:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
        //not sure if this accounts for non-int inputs, such as spaces or strings
            std::cout << "Invalid input. Please select a valid option." << std::endl;
            break;
        }
    }
    return 0;
}