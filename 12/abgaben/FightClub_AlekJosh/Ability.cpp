#include "Ability.h"

Ability::Ability(string name, int damage)
{
    //ctor
    this->name = name;
    this->damage = damage;
}

Ability::~Ability()
{
    //dtor
}
