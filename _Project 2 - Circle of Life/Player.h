#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include "Familiar.h"

class Player {
    private:
        static const int MAX_STAT = 1000;
        static const int MIN_STAT = 100;
        static const int MAX_AGE = 20;
        static const int MIN_AGE = 1;

        std::string _name;
        int _agility, _mana, _wisdom, _sardines, _age, _track;
        Familiar _familiar;
        std::string _player_name;

        bool isValid(int stat) const {
            return stat <= MAX_STAT && stat >= MIN_STAT;
        }
    public:
        Player();
        Player(std::string name, int age, int agility, int mana, int wisdom, int sardines);

        std::string getName() const {return _name;}
        int getAgility() const {return _agility;}
        int getMana() const {return _mana;}
        int getWisdom() const {return _wisdom;}
        int getSardines() const {return _sardines;}
        int getAge() const {return _age;}
        std::string getPlayerName() const {return _player_name;}
        Familiar getFamiliar() const {return _familiar;}

        bool setName(std::string name);
        bool setAgility(int agility);
        bool setMana(int mana);
        bool setWisdom(int wisdom);
        void setSardines(int sardines);
        bool setAge(int age);
        void setfamiliar(Familiar familiar);
        void setTrack(int track);
        bool setPlayerAge(std::string player_name);
        void adjustStats(int adjustment);

        void printStats();

        void refactorStats();
};

#endif