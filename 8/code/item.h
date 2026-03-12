#ifndef ITEM_H
#define ITEM_H

#include <string>

// Gegenstandstypen: 0=Staerke, 1=Geschicklichkeit, 2=Weisheit
class Item {
private:
    int type;

public:
    Item(int type);
    std::string getName();
    int getAttributeType();
};

#endif
