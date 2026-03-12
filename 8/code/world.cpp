#include "world.h"
#include <iostream>

GameWorld::GameWorld() {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            world[y][x] = 0;
        }
    }
}

void GameWorld::setField(int x, int y, int type) {
    world[y][x] = type;
}

char GameWorld::getSymbol(int x, int y) {
    int type = world[y][x];
    if (type == 0) return '.';
    if (type == 1) return '!';
    if (type == 2) return '~';
    if (type == 3) return '*';
    return '?';
}

void GameWorld::handleField(int x, int y, Character &player) {
    int type = world[y][x];
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
    world[y][x] = 0;
}
