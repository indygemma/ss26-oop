#include "specialAbility.h"
#include "Character.h"
#include <iostream>
using namespace std;

specialAbility::specialAbility(string name, int damage) : Ability(name, damage)
{
    //ctor
}

void specialAbility::execute(Character& source, Character& target){
    cout << source.getName() << " used " << this->name << ". " << endl;
    target.takeDmg(this->damage);
}

specialAbility::~specialAbility()
{
    //dtor
}
