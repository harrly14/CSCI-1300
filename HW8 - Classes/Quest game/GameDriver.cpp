#include <iostream>
#include <fstream>
#include "Game.h"

/*
write a function loadcharacters() that reads data and fills it 
into an array of character objects. return true if successfull. 
return false if file cannot be opened. ignore empty lines. first line is ignored
*/
//split function loaded from CSCI1300 library (thats why its kinda shit)
int split(std::string input, char delimiter, std::string line_arr[], int arrSize){
    // define a temporary string and helper variables
    std::string temp = "";
    int size = 0;
    
    // check for empty input
    if(input == "")
    {
        return size;
    }

    else
    {
        for(unsigned int i = 0; i < input.length(); i++)
        {
            // Check for delimiter
            if(input[i] != delimiter) 
            {
                // If the current character is not a delimeter, add it to the temporary string
                temp = temp + input[i];
            }

            // if the current chracter is a delimeter
            else
            {
                size++;
                // check if size > arrSize
                if (size > arrSize){
                    size = -1;
                    return size;
                }

                // add temporary string to the array
                // set temp to an empty string
                // check if last string is the longest
                else{
                    line_arr[size - 1] = temp;
                    temp = "";                    
                }
            }
        }
        // Account for final string
        size++;
        // check if size > arrSize
        if (size > arrSize){
            return -1;
        }

        // add temporary string to the array
        else{
            line_arr[size - 1] = temp;
        }
    }

    return size;
}

bool loadCharacters(std::string filename, Character characters[], const int CHARACTERS_SIZE, bool is_creature){
    std::ifstream file_in(filename);
    if (file_in.fail()) {
        return false;
    }
    std::string line;
    //removing the first line
    getline(file_in,line);

    int i = 0;
    while (getline(file_in,line) && i < CHARACTERS_SIZE) {
        const int arrSize = 4;
        std::string line_arr[arrSize];
        split(line, '|', line_arr, arrSize);
        characters[i].setName(line_arr[0]);
        characters[i].setHealth(stod(line_arr[1]));
        characters[i].setMana(stoi(line_arr[2]));
        characters[i].setStatus(line_arr[3][0]);
        characters[i].setIsCreature(is_creature);
        ++i;
    }

    return true;
}


int main() {
    Character players[3] = {};

loadCharacters("players_full.txt", players, 3, false);

for(int i = 0; i < 3; i++){
    players[i].printStats();
    std::cout << "----------------------------------------------" << std::endl;
}
}