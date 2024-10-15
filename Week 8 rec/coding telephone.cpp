#include <iostream>
#include <cmath>
using namespace std;




const int N = 50;
const int HEIGHT = 15;
const int LENGTH = 40;
const char SYMBOL = '*';
const double PI = 4 * atan(1.0);




void StartingShape(string ART[]){
//create blank ascii 2d array
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < LENGTH; j++) {
            ART[i] += ' ';
        }
    }




    //add stem
    ART[0][LENGTH/2-1] = ')';
    ART[0][LENGTH/2+2] = '|';
    ART[1][LENGTH/2-2] = ')';
    ART[1][LENGTH/2+2] = '|';
    //add eyes
    ART[HEIGHT/3].replace(LENGTH/2 - 3, 7, "/| |\\");
    ART[HEIGHT/3+1].replace(LENGTH/2 - 4, 9, "/_| |_\\");
}




void display(string ART[]){
//display it
for (int i = 0; i < HEIGHT; i++){
    cout << ART[i] << endl;
}
}




int main(){
    double dtheta = 2.0 * PI / N;
    string ART[HEIGHT];
    StartingShape(ART);
    // **** CODING TELEPHONE STARTS HERE ****
    //draw a circle with asterisks:


    for(int t = 0; t < N; t++)
    {
        double theta = t*dtheta;
        //wrong: int i = (1/2)*(1+cos(theta))(HEIGHT-3)+2.5;
        int i = .5*(1+cos(theta))*(HEIGHT-3)+2.5;
        //wrong: int j = (1/2)*(1+sin(theta))(LENGTH-3)+.5;
        int j = .5*(1+sin(theta))*(LENGTH-3)+.5;
        ART[i][j] = SYMBOL; //had to add = SYMBOL
    }


    //draw a mouth with slashes and backslashes




        for(int i = LENGTH/4; i < LENGTH/4*3; i++)
        {
            if ( (i % 2) == 1)
            {
                ART[HEIGHT*2/3][i] = '\\'; //had to change from "\esc" to "\\"
            }
            else
            {
                ART [HEIGHT*2/3][i]= '/';
            }
        }




    // **** CODING TELEPHONE ENDS HERE ****
    display(ART);
    return 0;
}
