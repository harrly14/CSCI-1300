#include <iostream>
#include <vector>
#include <string>
using namespace std;

void mostPopularWord(string words[], const int WORDS_SIZE) {
    string best_word = "";
    int best_word_counter = 0;
    vector<int> best_word_indexes;

    for (int i = 0; i < WORDS_SIZE; ++i) {
        int this_word_counter = 0;
        vector<int> this_word_indexes;

        for (int j = 0; j < WORDS_SIZE; ++j) {
            if (words[j] == words[i]) {
                ++this_word_counter;
                this_word_indexes.push_back(j);
            }
        }

        if (this_word_counter > best_word_counter || 
            (this_word_counter == best_word_counter && 
             this_word_indexes.back() > best_word_indexes.back())) {
            best_word_counter = this_word_counter;
            best_word = words[i];
            best_word_indexes = this_word_indexes;
        }
    }

    cout << "The most popular word: " << best_word << endl;
    cout << "Frequency: " << best_word_counter << endl;
    cout << "Found at pos: ";
    for (int index : best_word_indexes) {
        cout << index << " ";
    }
    cout << endl;
}

int main() {
    const int WORDS_SIZE = 6;
    string words[WORDS_SIZE] = {"amazon", "amazon", "amazon", "google", "google", "google"};
    mostPopularWord(words, WORDS_SIZE);
    return 0;
}