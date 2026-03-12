#include "character.h"
#include <iostream>

Character::Character() : health(5), relics(0) {
    items[0] = 0;
    items[1] = 0;
    items[2] = 0;
}

int Character::getHealth() { return health; }
int Character::getRelics() { return relics; }
void Character::loseHealth() { health--; }
void Character::gainHealth() { health++; }
void Character::addRelic() { relics++; }

void Character::addItem(int type) {
    items[type]++;
    if (type == 0) std::cout << "Staerkehandschuhe gefunden!" << std::endl;
    if (type == 1) std::cout << "Geschicklichkeitsstiefel gefunden!" << std::endl;
    if (type == 2) std::cout << "Weisheitsrolle gefunden!" << std::endl;
}

bool Character::useItem(int type) {
    if (items[type] > 0) {
        items[type]--;
        return true;
    }
    return false;
}
