#include <iostream>
#include <algorithm>
using namespace std; 

bool is_one(char c) {
	if (c == '1') {
		return true;
	}
	return false;
}

int main() { 
	string grid = "12312312";
	int count = 0; 
	for (char c : grid) {
	count += count_if(grid.begin(), grid.end(), is_one(c));
	}

	
}