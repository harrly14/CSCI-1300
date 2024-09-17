#include <iostream>
using namespace std;

int main() {
    double int_velo, final_velo;
    char fuel;
	int fnl_vls[3][3] = {{5,10,20},{6,12,24},{3,6,9}}, vls_lookup, secval;

    cout << "Enter the initial velocity:" << endl;
    cin >> int_velo;
    cout << "Enter the fuel type:" << endl;
    cin >> fuel;
    if(int_velo<0) {
        cout << "Invalid fuel type or initial velocity." << endl;
    } else if (int_velo<10) {
		vls_lookup = 0;
	} else if (int_velo>=10&&int_velo<=40) {
		vls_lookup = 1;
	}else if (int_velo>40) {
		vls_lookup = 2;
	}
	switch(fuel){
		case 'A':
			secval = 0;
			break;
		case 'B':
			secval = 1;
			break;
		case 'C':
			secval = 2;
			break;
	}
    final_velo = int_velo+(20*fnl_vls[vls_lookup][secval]);
    cout << "The final velocity is "  <<final_velo<< " m/s." << endl;
    return 0;
}