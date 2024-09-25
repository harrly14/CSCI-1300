/*
calculate ingredients for candies
use pumpkin candy volume (volume = 4/3piabc), where a, b, and c are radii alond x,y,z axes
use witch's hat candy volue (volume = 1/3pir^2h) where r= radius, h=height

3.2.a - pseudocode: 

include iostream
include cmath
include iomanip
include cassert

declare global var pi = 3.14. //could use M_PI, but i only want 2 decimal places 

define a double function with x,y,z params
    return 4/3*pi*x*y*z

define a double function with radius, height params
return 1/3*pi*(pow(r,2))*2*h

3.2.b - 
pumpkin - x=1, b=2, c=3, v=25.12
hat - radius=2, height=3, v=12.56

3.2.c - 
assert(pupmkinvolume(1,2,3))
assert(pumpkinvolume(1,2,3) == 25.12)
assert(hatvolume(2,3))
assert(hatvolume(2,3) == 12.56)


*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;

double pi = 3.14; //again i could use M_PI, but i dont want the values returned to go on forever, so this makes sure they stop at 2 decimal places

double calculateVolumeOfPumpkinCandy(double radiusX, double radiusY, double radiusZ){
    return 4.0/3.0*pi*radiusX*radiusY*radiusZ;

}

double calculateVolumeOfWitchHatCandy(double radius, double height) { 
    return 1.0/3.0*pi*(pow(radius,2))*height;
 }

int main() {
    assert(calculateVolumeOfPumpkinCandy(1,2,3));
    assert(calculateVolumeOfPumpkinCandy(1,2,3) == 25.12);
    assert(calculateVolumeOfWitchHatCandy(2,3));
    assert(calculateVolumeOfWitchHatCandy(2,3) == 12.56);
    return 0;
}