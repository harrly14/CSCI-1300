/*
calculate ingredients for candies
use pumpkin candy volume (volume = 4/3piabc), where a, b, and c are radii alond x,y,z axes
use witch's hat candy volue (volume = 1/3pir^2h) where r= radius, h=height

3.2.a - pseudocode: 

include iostream
include cmath
include iomanip
include cassert

define a double function with x,y,z params
    return 4/3*pi*x*y*z rounded to two decimal places

define a double function with radius, height params
return 1/3*pi*(pow(r,2))*2*h rouded to two decimal places

3.2.b - 
pumpkin - x=1, b=2, c=3, v=25.13
hat - radius=2, height=3, v=12.57

3.2.c - 
assert(pupmkinvolume(1,2,3))
assert(pumpkinvolume(1,2,3) == 25.13)
assert(hatvolume(2,3))
assert(hatvolume(2,3) == 12.57)
*/
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;

double calculateVolumeOfPumpkinCandy(double radiusX, double radiusY, double radiusZ){
    return round(4.0/3.0*M_PI*radiusX*radiusY*radiusZ * 100.0)/100.0; 

}

double calculateVolumeOfWitchHatCandy(double radius, double height) { 
    return round(1.0/3.0*M_PI*(pow(radius,2))*height *100.0)/100.0;
 }

int main() {
    assert(calculateVolumeOfPumpkinCandy(1,2,3) == 25.13);
    assert(calculateVolumeOfWitchHatCandy(2,3) == 12.57);
    return 0;
}