#ifndef FIELD_H
#define FIELD_H

#include "character.h"

// Feldtypen: 0=Leer, 1=Gefahr, 2=Brunnen, 3=Relikt
class Field {
private:
    int type;

public:
    Field(int type);
    char getSymbol();
    void onEnter(Character &player);
};

#endif
