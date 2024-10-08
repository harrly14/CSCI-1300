#include <iostream>
using namespace std; 
int main() { 
	string fruits[] = {"Apple", "Banana", "Cherry", "Date", "Fig", "Grape", "Mango"}; 
	int longest_string = fruits[0].length(); 
	for (int i = 1; i < 7; i++){ 
		if (fruits[i].length() > longest_string){ //FILL IN THIS LINE 
			longest_string = fruits[i].length(); 
		} 
	} 
	for (int i = 0; i < longest_string; i++){ 
		for (int j = 0; j < 7; j++){
			if (i < static_cast<int>(fruits[j].length())){ 
				cout << fruits[j][i] << endl; // FILL IN THIS LINE 
			} 
		} 
	} 
}