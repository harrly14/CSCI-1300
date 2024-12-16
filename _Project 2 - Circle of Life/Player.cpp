#include "Player.h"

Player::Player(){
    //min values for each
    _name = "";
    _age = MIN_AGE;
    _agility = MIN_STAT;
    _mana = MIN_STAT;
    _wisdom = MIN_STAT;
    _sardines = 0;
    _familiar = Familiar();
}

Player::Player(std::string name, int age, int agility, int mana, int wisdom, int sardines){
    _age = age;
    _sardines = sardines;
    _name = name;

    if (!isValid(agility)) {
        _agility = MIN_STAT;
    } else {
        _agility = agility;  
    }

    if (!isValid(mana)) {
        _mana = MIN_STAT;
    } else {
        _mana = mana;  
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
        if (!isalpha(c) && c != ',' && c != ' ') {
            std::cout << "Invalid character \"" << c <<"\" in name." << std::endl;
            return false;
        }
    }
    _name = name;
    return true;
}

bool Player::setAgility(int agility){
    if (!isValid(agility)) {
        //std::cout << "Unable to set agility with value: " << agility << std::endl;
        return false;
    } 
    
     _agility = agility;
     return true;
}

bool Player::setMana(int mana){
    if (!isValid(mana)) {
        //std::cout << "Unable to set mana with value: " << mana << std::endl;
        return false;
    } 
    
     _mana = mana;
     return true;
}

bool Player::setWisdom(int wisdom){
    if (!isValid(wisdom)) {
        //std::cout << "Unable to set wisdom with value: " << wisdom << std::endl;
        return false;
    } 
    
     _wisdom = wisdom;
     return true;
}

void Player::setSardines(int sardines){
    _sardines = sardines;
}

bool Player::setAge(int age){
    if (age < MIN_AGE || age > MAX_AGE) {
        std::cout << "Unable to set age with value: " << age << std::endl;
        return false;
    } 
    
     _age = age;
     return true;
}

void Player::setfamiliar(Familiar familiar){
    _familiar = familiar;
}

void Player::setTrack(int track){
    if (track != 1 && track != 2) {
        std::cout << "Unable to set player track" << std::endl;
    }
    else {
        _track = track;
    }
}

bool Player::setPlayerAge(std::string player_name){
    //checks that the name is only letters
    for (char c : player_name) {
        if (tolower(c) < 97 || tolower(c) > 172) {
            std::cout << "Invalid player name. Please try again." << std::endl;
            return false;
        }
    }
    _player_name = player_name;
    return true;
}

void Player::adjustStats(int adjustment){
    _agility += adjustment;
    _mana += adjustment;
    _wisdom += adjustment;

    if (_agility < MIN_STAT ) {
        _agility = MIN_STAT;
    } else if (_agility > MAX_STAT) {
        _agility = MAX_STAT;
    }

    if (_mana < MIN_STAT ) {
        _mana = MIN_STAT;
    } else if (_mana > MAX_STAT) {
        _mana = MAX_STAT;
    }

    if (_wisdom < MIN_STAT ) {
        _wisdom = MIN_STAT;
    } else if (_wisdom > MAX_STAT) {
        _wisdom = MAX_STAT;
    }
}

void Player::printStats(){
    std::cout << _name << ", age " << _age << std::endl
    << "Agility: " << _agility << std::endl 
    << "Mana: " << _mana << std::endl 
    << "Wisdom: " << _wisdom << std::endl 
    << "Sardines: " << _sardines << std::endl;
}

void Player::refactorStats() {
    while (_agility >= MIN_STAT+100) {
        _agility -= 100;
        _sardines += 1000;
    }
    while (_mana >= MIN_STAT+100) {
        _mana -= 100;
        _sardines += 1000;
    }
    while (_wisdom >= MIN_STAT+100) {
        _wisdom -= 100;
        _sardines += 1000;
    }
}
