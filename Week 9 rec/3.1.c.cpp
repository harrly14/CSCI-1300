#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int split(string input_string, char separator, string message_fragments[], const int ARR_SIZE){
    if (input_string.length() == 0){
        return 0;
    } 
    int sep_counter = 0;
    int sep_index = -1;
    for (unsigned int i = 0; i < input_string.length(); ++i){
        if (input_string[i] == separator){
            message_fragments[sep_counter] = input_string.substr(sep_index+1, i - sep_index-1);
            sep_index = i;
            ++sep_counter;
            if (sep_counter >= ARR_SIZE) {
                return -1;
            }
            message_fragments[sep_counter] = input_string.substr(i+1);
        } 
    }

    if (sep_counter == 0) {
        message_fragments[0] = input_string;
    }

    return sep_counter + 1;
}

string appendPrepend(string message){
    const int LENGTH = 4;
    string message_fragments[LENGTH] = {};
    string empty_word = "";

    int num_of_frags = split(message, ' ', message_fragments, LENGTH); //added semi-colon, removed brackets from message fragments. set equal to an int var
    assert(num_of_frags<=LENGTH); //added semi-colon. changed epression so it isnt checking out of bounds indices. 
    string answer; //dont need the word variable
    
    for(int i = 0; i < LENGTH; i++){ //changed i == 0 to i = 0
        answer += '_' + message_fragments[i] + '_'; //changed from message to message_fragments[i]. changed "" to ''. 
    }
    
    int first_word_length = message_fragments[0].length();
    int second_word_length = message_fragments[1].length();
    assert(message_fragments[1] == answer.substr(first_word_length+3, second_word_length)); //added semi-colon. changed = to ==
    return answer;
}


int main(){
    cout << "Please enter the string message:" << endl;
    string message;
    getline(cin, message);
    cout << appendPrepend(message);
}