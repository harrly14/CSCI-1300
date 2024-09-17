<<<<<<< HEAD
/* pool has water in it. pool needs to be filled.
water level decreases slightly every hour at a constant rate. 
take the hour as input (integer) --> predict pools water level
over time. 

Sample output:
How many hours have passed?
22
The indoor pool has 23.4 inches of water, and the outdoor pool has 26.4 inches of water.

To find the equation we will be using, we use the table provided. There is an indoor
and outdoor pool. 

Indoor: initial- 19, fill- .6, leakage-.4
Outdoor: initial- 22, fill- .3, leakage- .1

solution: include iostream
create doubles for indoor and outdoor, create int for hour
cout the first prompt and cin the hour
indoor = 19 + (.6*hour) - (.4*hour)
outdoor = 22 + (.3*hour) - (.1*hour)
output the data into the prompts
set precision to 1 fixed (?)
*/

#include <iostream>
using namespace std;

main() {
    double indoor, outdoor;
    int hour;
    cout << "How many hours have passed?" << endl;
    cin >> hour;
    indoor = 19+(.6*hour)-(.4*hour);
    outdoor = 22+(.3*hour)-(.1*hour);
    cout <<  "The indoor pool has "<< indoor << " inches of water, and the outdoor pool has " << outdoor 
    << " inches of water." << endl;
    return 0;
=======
/* pool has water in it. pool needs to be filled.
water level decreases slightly every hour at a constant rate. 
take the hour as input (integer) --> predict pools water level
over time. 

Sample output:
How many hours have passed?
22
The indoor pool has 23.4 inches of water, and the outdoor pool has 26.4 inches of water.

To find the equation we will be using, we use the table provided. There is an indoor
and outdoor pool. 

Indoor: initial- 19, fill- .6, leakage-.4
Outdoor: initial- 22, fill- .3, leakage- .1

solution: include iostream
create doubles for indoor and outdoor, create int for hour
cout the first prompt and cin the hour
indoor = 19 + (.6*hour) - (.4*hour)
outdoor = 22 + (.3*hour) - (.1*hour)
output the data into the prompts
set precision to 1 fixed (?)
*/

#include <iostream>
using namespace std;

main() {
    double indoor, outdoor;
    int hour;
    cout << "How many hours have passed?" << endl;
    cin >> hour;
    indoor = 19+(.6*hour)-(.4*hour);
    outdoor = 22+(.3*hour)-(.1*hour);
    cout <<  "The indoor pool has "<< indoor << " inches of water, and the outdoor pool has " << outdoor 
    << " inches of water." << endl;
    return 0;
>>>>>>> 6c2cf93a5ffcc7c8cdeb3eac2fcaa8177f3ec084
}