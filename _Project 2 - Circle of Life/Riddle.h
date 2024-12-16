#include <string>
#ifndef RIDDLE_H
#define RIDDLE_H
struct Riddle {
    int _line_num;
    std::string _question;
    std::string _answer;
    Riddle(int line, std::string q, std::string a) {
        _line_num = line;
        _question = q;
        _answer = a;
    }
};
#endif