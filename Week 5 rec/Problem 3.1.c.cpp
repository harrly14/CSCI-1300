#include <iostream>
#include <cassert>
using namespace std;

bool idLengthCheck(int ID)
{
    if (ID >= 9999999 && ID < 100000000) //changd or to and
    {
        return true;
    }
    return false;
}

int main()
{
    assert(idLengthCheck(12345678));
    assert(idLengthCheck(123456789) == false); //removed quotes. changed False to false
    return 0;
}