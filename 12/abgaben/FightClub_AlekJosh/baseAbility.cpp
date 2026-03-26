#include "baseAbility.h"
#include "Character.h"
#include <iostream>
using namespace std;

baseAbility::baseAbility(string name, int damage) : Ability(name, damage)
{
    //ctor
}

void baseAbility::execute(Character& source, Character& target){
    cout << source.getName() << " used " << this->name << ". " << endl;
    target.takeDmg(this->damage);
}

baseAbility::~baseAbility()
{
    //dtor
}
