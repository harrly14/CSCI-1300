#ifndef FAMILIAR_H
#define FAMILIAR_H
#include <string>
struct Familiar{
    int _line_num;
    std::string _name;
    std::string _power;
    Familiar() {
        _line_num = -1;
        _name = "";
        _power = "";
    }
    Familiar(int num, std::string name, std::string power){
        _line_num = num;
        _name = name;
        _power = power;
    }
};
#endif