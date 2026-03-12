#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
private:
    int health;
    int relics;
    int items[3]; // Anzahl pro Typ: 0=Staerke, 1=Geschick, 2=Weisheit

public:
    Character();
    int getHealth();
    int getRelics();
    void loseHealth();
    void gainHealth();
    void addRelic();
    void addItem(int type);
    bool useItem(int type);
};

#endif
