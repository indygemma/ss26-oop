#include "field.h"
#include <iostream>

Field::Field(int type) : type(type) {}

char Field::getSymbol() {
    if (type == 0) return '.';
    if (type == 1) return '!';
    if (type == 2) return '~';
    if (type == 3) return '*';
    return '?';
}

void Field::onEnter(Character &player) {
    if (type == 0) {
        // Leeres Feld — nichts passiert
    }
    if (type == 1) {
        std::cout << "Gefahr! Du verlierst 1 HP." << std::endl;
        player.loseHealth();
    }
    if (type == 2) {
        std::cout << "Brunnen! Du erhaeltst 1 HP." << std::endl;
        player.gainHealth();
    }
    if (type == 3) {
        std::cout << "Relikt gefunden!" << std::endl;
        player.addRelic();
    }
}
