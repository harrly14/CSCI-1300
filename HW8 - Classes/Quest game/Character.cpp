#include <iostream>
#include "Character.h"
#include <iomanip>

Character::Character(){
    _mana = 0;
    _health = 0;
    _name = "";
    _status = 'A';
    _isCreature = false;
}
Character::Character(std::string name, double health, int mana, char status, bool isCreature){
    _name = name;
    if (health > 0) {
        _health = health;
    } else {
        _health = 0;
    }
    if (mana > 0) {
        _mana = mana;
    } else {
        _mana = 0;
    }
    if (status == 'C' || status == 'F') {
        _status = status;
    } else {
        _status = 'A';
    }
    _isCreature = isCreature;
}
std::string Character::getName(){
    return _name;
}
double Character::getHealth(){
    return _health;
}
int Character::getMana(){
    return _mana;
}
char Character::getStatus(){
    return _status;
}
bool Character::getIsCreature(){
    return _isCreature;
}
void Character::setName(std::string name){
    _name = name;
}
void Character::setHealth(double health){
    if (health >= 0) {
        _health = health;
    }
}
void Character::setStatus(char status){
    if (status == 'A' || status == 'C' || status == 'F'){
        _status = status;
    }
}
void Character::setMana(int mana){
    if (mana >= 0) {
        _mana = mana;
    }
}
void Character::setIsCreature(bool is_enemy){
    _isCreature = is_enemy;
}
void Character::printStats(){
    //all double values are printed to 2 decimal places
    std::cout << _name << "'s stats:" << std::endl;
    std::cout << "Health: " << std::fixed << std::setprecision(2) <<  _health << std::endl;
    std::cout << "Status: " << _status << std::endl;
    std::cout << "Mana: " << _mana << std::endl;
    std::cout << "Is Creature: ";
    if (_isCreature){
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}