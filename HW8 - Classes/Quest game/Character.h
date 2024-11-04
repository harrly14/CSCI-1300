#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character {
    private:
        std::string _name;
        double _health;
        int _mana;
        char _status;
        bool _isCreature;
    public:
        Character();
        Character(std::string, double, int, char, bool);
        std::string getName();
        double getHealth();
        int getMana();
        char getStatus();
        bool getIsCreature();
        void setName(std::string name);
        void setHealth(double health);
        void setStatus(char status);
        void setMana(int mana);
        void setIsCreature(bool is_enemy);
        void printStats();
};



#endif