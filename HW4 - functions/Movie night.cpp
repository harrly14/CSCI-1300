#include <iostream>
using namespace std;

int main() {
    int genre, directors, movie;
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
    switch(genre) {
        case 1:
            cout << "Select the director: (1) Pete Docter (2) Brad Bird (3) Andrew Stanton" << endl;
            cin >> directors;
            switch(directors){
                case 1:
                    cout << "Select the movie: (1) Monsters, Inc. (2) Inside Out" << endl;
                    cin >> movie;
                    switch(movie) {
                        case 1:
                            cout << "You have reserved the movie: "<< movieslist[0][movie-1] << endl;
                            break;
                        case 2:
                            cout << "You have reserved the movie: "<< movieslist[0][movie-1] << endl;
                            break;
                        default:
                            cout << "Please enter a valid input" << endl;
                            break; 
                    }
                    break;
                case 2:
                    cout << "Select the movie: (1) The Incredibles (2) Ratatouille" << endl;
                    cin >> movie;
                    switch(movie) {
                        case 1:
                            cout << "You have reserved the movie: "<< movieslist[1][movie-1] << endl;
                            break;
                        case 2:
                            cout << "You have reserved the movie: "<< movieslist[1][movie-1] << endl;
                            break;
                        default:
                            cout << "Please enter a valid input" << endl;
                            break; 
                    }
                    break;
                case 3:
                    cout << "Select the movie: (1) Finding Nemo (2) WALL-E" << endl;
                    cin >> movie;
                    switch(movie) {
                        case 1:
                            cout << "You have reserved the movie: "<< movieslist[2][movie-1] << endl;
                            break;
                        case 2:
                            cout << "You have reserved the movie: "<< movieslist[2][movie-1] << endl;
                            break;
                        default:
                            cout << "Please enter a valid input" << endl;
                            break; 
                    }
                    break;
                default:
                    cout << "Please enter a valid input" << endl;
                    break;  
            }
            break;
        case 2:
            cout << "Select the director: (1) Steven Spielberg (2) Jon Favreau (3) Robert Zemeckis" << endl;
            cin >> directors;
            switch(directors){
                case 1:
                    cout << "Select the movie: (1) E.T. the Extra-Terrestrial (2) The BFG" << endl;
                    cin >> movie;
                    switch(movie) {
                        case 1:
                            cout << "You have reserved the movie: "<< movieslist[3][movie-1] << endl;
                            break;
                        case 2:
                            cout << "You have reserved the movie: "<< movieslist[3][movie-1] << endl;
                            break;
                        default:
                            cout << "Please enter a valid input" << endl;
                            break; 
                    }
                    break;
                case 2:
                    cout << "Select the movie: (1) The Jungle Book (2016) (2) Elf" << endl;
                    cin >> movie;
                    switch(movie) {
                        case 1:
                            cout << "You have reserved the movie: "<< movieslist[4][movie-1] << endl;
                            break;
                        case 2:
                            cout << "You have reserved the movie: "<< movieslist[4][movie-1] << endl;
                            break;
                        default:
                            cout << "Please enter a valid input" << endl;
                            break; 
                    }
                    break;
                case 3:
                    cout << "Select the movie: (1) Back to the Future (2) Who Framed Roger Rabbit" << endl;
                    cin >> movie;
                    switch(movie) {
                        case 1:
                            cout << "You have reserved the movie: "<< movieslist[5][movie-1] << endl;
                            break;
                        case 2:
                            cout << "You have reserved the movie: "<< movieslist[5][movie-1] << endl;
                            break;
                        default:
                            cout << "Please enter a valid input" << endl;
                            break; 
                    }
                    break;
                default:
                    cout << "Please enter a valid input" << endl;
                    break;  
            }
            break;
        default: 
            cout << "Please enter a valid input" << endl;
            break;
    }
    return 0;
}