#include "Character.h"
#include <iostream>

using namespace std;
Character::Character(string name, unique_ptr<Ability> a1, unique_ptr<Ability> a2, int hp, int maxhp, int wins, int losses)
{
    //ctor
    this->name = name;
    this->hp = hp;
    hp = 100;
    this->maxhp = maxhp;
    maxhp = 100;
    this->wins = 0;
    this->losses = 0;

    abilities.push_back(move(a1));
    abilities.push_back(move(a2));
}

void Character::useAbility(int index, Character& opponent){
    abilities[index]->execute(*this, opponent);
}

string Character::getAbilityName(int index){
    if (index >= 0 && index < abilities.size()) {
        return abilities[index]->getName();
    }
    return "Unknown ability";
}

void Character::takeDmg(int amount){
    hp = hp - amount;
    if(hp < 0){
        hp = 0;
    }
    cout << name << " took " << amount << " damage. HP: " << hp << endl;
}


Character::~Character()
{
    //dtor
}
