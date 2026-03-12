#include <cassert>
#include <iostream>
#include "character.h"
#include "field.h"
#include "item.h"
#include "world.h"

int main() {
    // ===================================================
    // Diese main-Datei zeigt, wie der Code AKTUELL
    // funktioniert. Alle Typen werden per Integer
    // unterschieden. Kompilieren Sie diesen Code zuerst,
    // um zu sehen, dass alles funktioniert.
    //
    // Kompilieren mit:
    //   g++ -o vorher main_vorher.cpp character.cpp field.cpp item.cpp world.cpp
    // ===================================================

    // --- Felder testen ---
    Field empty(0);
    Field danger(1);
    Field well(2);
    Field relic(3);

    assert(empty.getSymbol() == '.');
    assert(danger.getSymbol() == '!');
    assert(well.getSymbol() == '~');
    assert(relic.getSymbol() == '*');

    Character player;
    assert(player.getHealth() == 5);
    assert(player.getRelics() == 0);

    empty.onEnter(player);
    assert(player.getHealth() == 5);

    well.onEnter(player);
    assert(player.getHealth() == 6);

    danger.onEnter(player);
    assert(player.getHealth() == 5);

    relic.onEnter(player);
    assert(player.getRelics() == 1);

    // --- Items testen ---
    Item gauntlets(0);
    Item boots(1);
    Item scroll(2);

    assert(gauntlets.getName() == "Staerkehandschuhe");
    assert(boots.getName() == "Geschicklichkeitsstiefel");
    assert(scroll.getName() == "Weisheitsrolle");

    assert(gauntlets.getAttributeType() == 0);
    assert(boots.getAttributeType() == 1);
    assert(scroll.getAttributeType() == 2);

    // --- Character-Inventar testen ---
    Character player2;
    player2.addItem(0);
    player2.addItem(1);
    player2.addItem(2);

    assert(player2.useItem(1) == true);
    assert(player2.useItem(1) == false);
    assert(player2.useItem(0) == true);

    // --- GameWorld testen ---
    GameWorld gw;

    // Standard: alle Felder leer
    assert(gw.getSymbol(0, 0) == '.');
    assert(gw.getSymbol(2, 2) == '.');

    // Felder setzen (Integer-Typen)
    gw.setField(0, 0, 2);  // Brunnen
    gw.setField(1, 0, 1);  // Gefahr
    gw.setField(2, 0, 3);  // Relikt

    assert(gw.getSymbol(0, 0) == '~');
    assert(gw.getSymbol(1, 0) == '!');
    assert(gw.getSymbol(2, 0) == '*');

    // handleField delegiert und setzt Feld auf leer
    Character gwPlayer;
    gw.handleField(0, 0, gwPlayer);
    assert(gwPlayer.getHealth() == 6);
    assert(gw.getSymbol(0, 0) == '.');

    gw.handleField(1, 0, gwPlayer);
    assert(gwPlayer.getHealth() == 5);

    gw.handleField(2, 0, gwPlayer);
    assert(gwPlayer.getRelics() == 1);

    std::cout << "Alle Tests bestanden! (vorher)" << std::endl;
    return 0;
}
