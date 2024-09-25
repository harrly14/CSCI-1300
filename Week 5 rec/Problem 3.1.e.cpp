/*The program below is a working program that uses the getPrice function to compute the
price of a wall frame of a given area and color. This code does not contain any syntax or logical errors.
However, it has multiple style errors making the code very difficult to read. These errors can range from
usage of unintended white space to having extraneous variables or clauses in your code. Identify the style
error(s) in the code below and rewrite the below code to improve readability.*/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;


double getPrice(double area, string color){
    assert(area>=0); 
    double cost = 0.0;
    if (color == "green"){
        cost = 4; 
    }
    else if (color == "red"){ 
        cost = 3; 
    }
    else if (color == "orange")
    {
        cost = 2;
    }
    else if (color == "blue")
    {
        cost = 1;
    } 

    return area * cost;
}


int main()
{
    string color;
    int area_choice;
    double area = 0;

    cout << "Enter the area of the frame: (1) 5x5 (2) 4x6 (3) 8x10" << endl;
    cin >> area_choice;
    assert(area_choice == 1 || area_choice == 2 || area_choice == 3);

    if(area_choice == 1){
        area = 5*5; 
    } else if (area_choice == 2){
        area = 4*6; 
    }else if (area_choice == 3){
        area = 8*10;
    }

    cout << "Enter the color of the frame: (green, red, orange, blue): ";
    cin >> color;
    assert(color == "green" || color == "red" || color == "orange" || color == "blue");
    cout << "You will receive a "<< color << " color frame with a price of $" << getPrice(area, color) << ". ";
    cout << "Thank you for your business."<<endl;
    return 0;
}
