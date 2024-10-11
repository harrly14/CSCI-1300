//no global vars
//no pass by reference
//all functions must match precisely
//well comment code
//create assert statements for each question to test the code

#include <cassert>

/*
- ORFs: specific regions of DNA strands
    - read in groups of three bases (called codons)
    - a coninuous sequence of DNA that starts with a codon and ends with a codon
    - start codon: ATG
    - end codons: TAA, TAG, TGA
    - number of bases between start and stop codons is % 3 = 0
- identify ORFs
function: void getCodingFrames(std::string strand)
    - print complete ORFs
    - if no reading frames: print "No reading frames found."
    - assume valid input
    - there could be multiple ORFs
*/
#include <iostream>

void getCodingFrames(std::string strand);

int main() {
    getCodingFrames("ATGATGATGTAGATGA");
        //ATGATGATGTAG
    //getCodingFrames("ATGATATAAGGGATTAGATGAGTAGATAGGAGTTAGTAGAGAGGAT");
        //ATGATATAA, ATGAGTAGATAG
    //getCodingFrames("TTTATGAGATTTTAGGGTTTTTGATGTTAGGATAGTTATGATAATAGTTTAA");
        //ATGAGATTTTAG, ATGTTAGGATAG, ATGATAATAGTTTAA
    getCodingFrames("ATGCTTAGCGATGAATGATCGTAAATGCGTGAATGGCCGTAGTGAATGCGTTAG");
        //ATGCTTAGCGATGAATGA, ATGCGTGAATGGCCGTAG, ATGCGTTAG
    //getCodingFrames("ATGAGTCGTAGTAAATGGCGATGTAGATGCCCGTAGGCTTAGGATGTGATGAATG");
        //ATGAGTCGTAGTAAATGGCGATGTAGATGCCCGTAG, ATGTGA
    getCodingFrames("ATAGATAGATGATAGTTGATATGGAT");
        //no reading frames
    return 0;
}

void getCodingFrames(std::string strand) {
    unsigned int starting_index = 0;
    int num_of_orfs_found = 0;
    
    //while you are starting within the strand
    while (starting_index <= strand.length()) {
        
        bool frame_open = false;
        //find the next start codon
        for (unsigned int i = starting_index; i <= strand.length()-3; i++) {
            std::string current_codon = strand.substr(i,3);
            if (current_codon == "ATG") {
                starting_index = i;
                frame_open = true;
                break;
            } 
        }

        bool stop_codon_found = false;

        //finding the stop codon: 
        //starts at the starting index because we dont care about anything before the start codon
        //ends at strand length - 3 because we are checking each group of 3 chars, so you dont need to check the last 2 chars
        unsigned int i = starting_index;
        while (frame_open && i < strand.length() - 2) {
            std::string current_codon = strand.substr(i,3);

            //if the codon we are checking is a stop codon
            if (current_codon == "TAG" || current_codon == "TGA" || current_codon == "TAA") {

                //index is i + 3 because we want to use the end of the codon, not the start
            unsigned int stop_codon_index = i + 3;
                //the ORF is from the start index to the stop index
            std::string ORF = strand.substr(starting_index, stop_codon_index-starting_index);
            std::cout << ORF << std::endl;
                
            num_of_orfs_found += 1;
            starting_index = stop_codon_index;
            stop_codon_found = true;
            frame_open = false;
            }
            i+=3;
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