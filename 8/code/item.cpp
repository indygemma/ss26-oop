#include "item.h"

Item::Item(int type) : type(type) {}

std::string Item::getName() {
    if (type == 0) return "Staerkehandschuhe";
    if (type == 1) return "Geschicklichkeitsstiefel";
    if (type == 2) return "Weisheitsrolle";
    return "Unbekannt";
}

int Item::getAttributeType() {
    return type;
}
