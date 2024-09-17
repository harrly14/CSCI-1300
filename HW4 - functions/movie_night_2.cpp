#include <iostream>
using namespace std;

int main() {
    int genre, directors, dr_index, movie;
    string movieslist[6][2] {
        {"Monsters, Inc.", "Inside Out"}, 
        {"The Incredibles", "Ratatouille"}, 
        {"Finding Nemo", "WALL-E"}, 
        {"E.T. the Extra-Terrestrial", "The BFG"},
        {"The Jungle Book (2016)", "Elf"},
        {"Back to the Future", "Who Framed Roger Rabbit"}
        };
    cout << "Select the genre: (1) Animation (2) Adventure" << endl;
    cin >> genre;

    switch(genre){
        case 1: 
            cout << "Select the director: (1) Pete Docter (2) Brad Bird (3) Andrew Stanton" << endl;
            break;
        case 2: 
            cout << "Select the director: (1) Steven Spielberg (2) Jon Favreau (3) Robert Zemeckis" << endl;
            break;
        default: 
            cout << "Please enter a valid input" << endl;
            break;
    }
    cin >> directors;
    dr_index = 3*(genre-1)+(directors-1);
    cout << "Select the movie: (1) "<<movieslist[dr_index][0] <<" (2) " << movieslist[dr_index][1]<< endl;
    cin >> movie;
    switch(movie){
        case 1:
        case 2:
            cout << "You have reserved the movie: "<< movieslist[dr_index][movie-1] << endl;
            break;
        default:
             cout << "Invalid movie. Please enter a valid input." << endl;
             break;
    }
}