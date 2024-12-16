#include "player.h"

Player::Player(){
    //min values for each
    _name = "";
    _age = MIN_AGE;
    _agility = MIN_STAT;
    _mana = MIN_STAT;
    _wisdom = MIN_STAT;
    _sardines = 0;
}
Player::Player(std::string name, int strength, int stamina, int wisdom){
    _age = MIN_AGE;
    _sardines = 0;
    _name = name;

    if (!isValid(strength)) {
        _agility = MIN_STAT;
    } else {
        _agility = strength;  
    }

    if (!isValid(stamina)) {
        _mana = MIN_STAT;
    } else {
        _mana = stamina;  
    }

    if (!isValid(wisdom)) {
        _wisdom = MIN_STAT;
    } else {
        _wisdom = wisdom;  
    }
}


bool Player::setName(std::string name){
    //checks that the name is only letters
    for (char c : name) {
        if (tolower(c) < 97 || tolower(c) > 172) {
            std::cout << "Invalid name. Please try again." << std::endl;
            return false;
        }
    }
    _name = name;
    return true;
}
bool Player::setStrength(int strength){
    if (!isValid(strength)) {
        std::cout << "Unable to set strength with value: " << strength << std::endl;
        return false;
    } 
    
     _agility = strength;
     return true;
}
bool Player::setStamina(int stamina){
    if (!isValid(stamina)) {
        std::cout << "Unable to set stamina with value: " << stamina << std::endl;
        return false;
    } 
    
     _mana = stamina;
     return true;
}
bool Player::setWisdom(int wisdom){
    if (!isValid(wisdom)) {
        std::cout << "Unable to set wisdom with value: " << wisdom << std::endl;
        return false;
    } 
    
     _wisdom = wisdom;
     return true;
}
bool Player::setPridePoints(int pride_points){
    //not sure on valid inputs for this yet, may have to add input validation later
    _sardines = pride_points;
    return true;
}
bool Player::setAge(int age){
    if (age < MIN_AGE || age > MAX_AGE) {
        std::cout << "Unable to set age with value: " << age << std::endl;
        return false;
    } 
    
     _age = age;
     return true;
}
void Player::magicSchool(int strength, int stamina, int wisdom){
    //add input validation? 
    //can it go below the min stat or above the max stat?
    _agility += strength;
    _mana += stamina;
    _wisdom += wisdom;
    _sardines -= 5000;
}
void Player::toDungeon(){
    //add input validation? 
    //can it go below the min stat or above the max stat?
    _sardines += 5000;
    _agility -= 2000;
    _wisdom -= 2000;
    _mana -=1000;
}
void Player::printStats(){
    std::cout << _name << ", age " << _age << std::endl
    << "Strength: " << _agility << std::endl 
    << "Stamina " << _mana << std::endl 
    << "Wisdom: " << _wisdom << std::endl 
    << "Pride Points: " << _sardines << std::endl;
}