#include <iostream>
#include <string>
#include <fstream> //need the fstream library
using namespace std;

int main(){
    ifstream my_file("visitors.txt");
    string full_line;
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int visitors[5] = {0, 0, 0, 0, 0}; //changed var name to match the rest of the code
    int i = 0;
    int traffic = 0;
    int j = 0;

    while (getline(my_file, full_line)){
        for(int i = 0; i < static_cast<int>(full_line.length()); i+=1){

            if(full_line[i] == ' ' && i < static_cast<int>(full_line.length())-1){
                visitors[i]++;
            }
        
            if(full_line[i] == ','){  //changed "" to '' to indicate a char
                visitors[i]++;
            }
        }

        if (visitors[i] < traffic){
            traffic = visitors[i];
            j = i;
        }

        i++;
    }

    cout << days[j] << " is the busiest day of the week at the motel." << endl;
    return 0;
}