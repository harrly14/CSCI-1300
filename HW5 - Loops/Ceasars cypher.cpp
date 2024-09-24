/*Write a program that encrypts lowercase letters using the Caesar cipher. Prompt the user for a letter
and a shift value in main(), and use the function specification listed below for encryption.*/
#include <iostream>
#include <vector>
using namespace std;

char encryptLower(char letter, int shift_value){
    if (isupper(letter)) {
        return letter;
    }
    //take the letter input, subtract 'a' to get the index of the letter in the alphabet, then add shift value to get index of new letter
    //mod by 26 to make sure we are still in the alphabet
    shift_value = (letter-'a'+shift_value)%26;

    //check for negative values and simply add 26 to them in that case
    if (shift_value < 0) {
        shift_value += 26;
    }
    return 'a'+shift_value;
}


int main(){
    char letter;
    int shift_value;
    cout << "Enter the lowercase character to encrypt:" << endl;
    cin >> letter;
    //perform input validation

    cout << "Enter the encryption value:" << endl;
    cin >> shift_value;
    cout << "Letter "<< letter << " was encrypted to "<< encryptLower(letter,shift_value)<< endl;
    return 0;
}