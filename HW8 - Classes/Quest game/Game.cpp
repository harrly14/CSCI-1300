#include <iostream>
#include "Game.h"

Game::Game(){
    _num_creatures = 0;
    _num_players = 0;
    for (int i = 0; i < 2; i++) {
        _players[i] = Character();
        _creatures[i] = Character();
    }
}
Game::Game(Character players[], Character creatures[], int num_players, int num_creatures){
    if (num_players > 2) {
        _num_players = 2;
    } else {
        _num_players = num_players;
    }
    if (num_creatures > 2) {
        _num_creatures = 2;
    } else {
        _num_creatures = num_creatures;
    }

    for (int i = 0; i < _num_players; ++i) {
            _players[i] = players[i];
    }
    for (int i = 0; i < _num_creatures; ++i) {
            _creatures[i] = creatures[i];
    }
}
int Game::getNumPlayers(){
    return _num_players;
}
int Game::getNumCreatures(){
    return _num_creatures;
}
void Game::setPlayersList(Character players[], int num_players){
    if (num_players > 2) {
        _num_players = 2;
    } else {
        _num_players = num_players;
    }
    for (int i = 0; i < 2 && i < _num_players; ++i) {
        _players[i] = players[i];
    }
}
void Game::setCreaturesList(Character creatures[], int num_creatures){
    if (num_creatures > 2) {
        _num_creatures = 2;
    } else {
        _num_creatures = num_creatures;
    }
    for (int i = 0; i < 2 && i < _num_creatures ; ++i) {
        _creatures[i] =  creatures[i];
    }
}
bool Game::setPlayer(int index, Character new_player){
    if (index >=0 && index <= _num_players) {
        _players[index] = new_player;
        return true;
    }
    return false;
}
bool Game::setCreature(int index, Character new_creature){
if (index >=0 && index <= _num_creatures) {
        _creatures[index] = new_creature;
        return true;
    }
    return false;
}
Character Game::getPlayer(std::string name){
    for (int i = 0; i < 2; ++i) {
        Character current_character = _players[i];
        if (current_character.getName() == name) {
            return current_character;
        }
    }
    Character new_character= Character();
    return new_character;
}
Character Game::getCreature(std::string name){
    for (int i = 0; i < 2; ++i) {
        Character current_creature = _creatures[i];
        if (current_creature.getName() == name) {
            return current_creature;
        }
    }
    Character new_creature= Character();
    return new_creature;
}
int Game::findPlayer(std::string name){
    for (int i = 0; i < 2; ++i) {
        Character current_character = _players[i];
        if (current_character.getName() == name) {
            return i;
        }
    }
    return -1;
}
int Game::findCreature(std::string name){
    for (int i = 0; i < 2; ++i) {
        Character current_creature = _creatures[i];
        if (current_creature.getName() == name) {
            return i;
        }
    }
    return -1;
}
void Game::printAllStats(){
    for (int i = 0; i < _num_players; ++i) {
        _players[i].printStats();
        std::cout << "----------------------------------------------" << std::endl;
    }
    for (int i = 0; i < _num_creatures; ++i) {
        _creatures[i].printStats();
        std::cout << "----------------------------------------------" << std::endl;
    }
}