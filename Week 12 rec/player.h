#include <iostream>
#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        const int MAX_STAT = 1000;
        const int MIN_STAT = 100;
        const int MAX_AGE = 20;
        const int MIN_AGE = 1;

        std::string _name;
        int _agility, _mana, _wisdom, _sardines, _age;

        bool isValid(int stat) const {
            return stat <= MAX_STAT && stat >= MIN_STAT;
        }
    public:
        Player();
        Player(std::string name, int strength, int stamina, int wisdom);

        std::string getName() const {return _name;}
        int getAgility() const {return _agility;}
        int getMana() const {return _mana;}
        int getWisdom() const {return _wisdom;}
        int getSardines() const {return _sardines;}
        int getAge() const {return _age;}

        bool setName(std::string name);
        bool setStrength(int strength);
        bool setStamina(int stamina);
        bool setWisdom(int wisdom);
        bool setPridePoints(int pride_points);
        bool setAge(int age);

        void magicSchool(int strength, int stamina, int wisdom);
        void toDungeon();
        void printStats();
};

#endif PLAYER