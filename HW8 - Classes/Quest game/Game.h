#ifndef GAME_H
#define GAME_H
#include <string>
#include "Character.h"

class Game {
    private: 
        Character _players[2];
        Character _creatures[2];
        int _num_players;
        int _num_creatures;
    public:
        Game();
        Game(Character[], Character[], int, int);
        int getNumPlayers();
        int getNumCreatures();
        void setPlayersList(Character[], int);
        void setCreaturesList(Character[], int);
        bool setPlayer(int, Character);
        Character getPlayer(std::string);
        bool setCreature(int, Character);
        Character getCreature(std::string);
        int findPlayer(std::string);
        int findCreature(std::string);
        void printAllStats();
};

#endif