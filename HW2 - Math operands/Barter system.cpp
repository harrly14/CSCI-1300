/*
4 potatoes = 1 watermelon
2 watermelon = 1 avocado
6 avocado = 1 chicken 

take the number of potatoes as an int and convert
it to the max number of chickens, avocados, watermelons,
and potatoes

Enter the number of potatoes:
200
Maximum number of chicken(s) 4, avocado(s) 1, watermelon(s) 0, potato(es) 0
*/

#include <iostream>
using namespace std;

main(){
    int potatoes, watermelons, avocados, chickens;
    cout << "Enter the number of potatoes:" << endl;
    cin >> potatoes;
    watermelons = potatoes / 4;
    potatoes = potatoes % 4;
    avocados = watermelons / 2;
    watermelons = watermelons % 2;
    chickens = avocados / 6;
    avocados = avocados % 6;
    cout << "Maximum number of chicken(s) " << chickens << ", avocado(s) " << avocados << ", watermelon(s) " << watermelons 
    << ", potato(es) " << potatoes << endl;
    return 0;
}