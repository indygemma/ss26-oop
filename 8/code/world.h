#ifndef WORLD_H
#define WORLD_H

#include "character.h"

// Spielwelt: 3x3 Raster mit Integer-Feldtypen
// Typen: 0=Leer, 1=Gefahr, 2=Brunnen, 3=Relikt
class GameWorld {
private:
    int world[3][3];

public:
    GameWorld();
    void setField(int x, int y, int type);
    char getSymbol(int x, int y);
    void handleField(int x, int y, Character &player);
};

#endif
