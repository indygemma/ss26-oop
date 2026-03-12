#include <cassert>
#include <iostream>
#include <string>
#include "character.h"
#include "field.h"
#include "item.h"
#include "world.h"

// ===================================================================
// Diese main-Datei DARF NICHT VERAENDERT werden!
//
// Sie beschreibt die Ziel-Architektur nach dem Refactoring.
// Ihre Aufgabe: Aendern Sie field.h/cpp, item.h/cpp, character.h/cpp
// und world.h/cpp so, dass dieser Code kompiliert und alle
// assert-Pruefungen bestehen.
//
// Kompilieren mit:
//   g++ -o nachher main.cpp character.cpp field.cpp item.cpp world.cpp
// ===================================================================

int main() {

    // ===========================================
    //  TEIL 1: Field-Hierarchie
    // ===========================================

    // Verschiedene Feldtypen werden als Unterklassen erzeugt
    // und ueber einen Basisklassen-Zeiger (Field*) verwendet.
    Field* empty  = new EmptyField();
    Field* danger = new DangerField();
    Field* well   = new WellField();
    Field* relic  = new RelicField();

    // Jede Unterklasse kennt ihr eigenes Symbol
    assert(empty->getSymbol()  == '.');
    assert(danger->getSymbol() == '!');
    assert(well->getSymbol()   == '~');
    assert(relic->getSymbol()  == '*');

    // onEnter() wird polymorph aufgerufen — der Aufrufer
    // muss nicht wissen, welcher Feldtyp vorliegt.
    Character player;
    assert(player.getHealth() == 5);
    assert(player.getRelics() == 0);

    // Leeres Feld: nichts passiert
    empty->onEnter(player);
    assert(player.getHealth() == 5);
    assert(player.getRelics() == 0);

    // Brunnen: +1 HP
    well->onEnter(player);
    assert(player.getHealth() == 6);

    // Gefahr: -1 HP
    danger->onEnter(player);
    assert(player.getHealth() == 5);

    // Relikt: +1 Relikt
    relic->onEnter(player);
    assert(player.getRelics() == 1);

    // Aufraeumen — virtueller Destruktor noetig!
    delete empty;
    delete danger;
    delete well;
    delete relic;

    // --- Polymorphes Array ---
    // Der grosse Vorteil: Alle Felder einheitlich behandeln
    Field* world[4];
    world[0] = new EmptyField();
    world[1] = new WellField();
    world[2] = new DangerField();
    world[3] = new RelicField();

    Character player2;
    // Alle Felder in einer Schleife abarbeiten —
    // ohne if-Kette, ohne Typ-Abfrage!
    for (int i = 0; i < 4; i++) {
        world[i]->onEnter(player2);
    }

    // leer(0) + brunnen(+1) + gefahr(-1) + relikt(0 HP)
    assert(player2.getHealth() == 5);
    // leer(0) + brunnen(0) + gefahr(0) + relikt(+1)
    assert(player2.getRelics() == 1);

    for (int i = 0; i < 4; i++) {
        delete world[i];
    }

    // ===========================================
    //  TEIL 2: Item-Hierarchie
    // ===========================================

    // Verschiedene Gegenstaende als Unterklassen
    Item* gauntlets = new Gauntlets();
    Item* boots     = new Boots();
    Item* scroll    = new Scroll();

    // Jede Unterklasse kennt ihren eigenen Namen
    assert(gauntlets->getName() == "Staerkehandschuhe");
    assert(boots->getName()     == "Geschicklichkeitsstiefel");
    assert(scroll->getName()    == "Weisheitsrolle");

    // Jede Unterklasse kennt ihren Attribut-Typ
    assert(gauntlets->getAttributeType() == 0);
    assert(boots->getAttributeType()     == 1);
    assert(scroll->getAttributeType()    == 2);

    delete gauntlets;
    delete boots;
    delete scroll;

    // ===========================================
    //  TEIL 3: Character mit polymorphem Inventar
    // ===========================================

    // Items werden als Zeiger uebergeben, nicht als int
    Character player3;
    player3.addItem(new Gauntlets());
    player3.addItem(new Boots());
    player3.addItem(new Gauntlets());
    player3.addItem(new Scroll());

    assert(player3.getInventorySize() == 4);

    // useItem sucht den ersten Gegenstand mit passendem Attribut-Typ
    assert(player3.useItem(1) == true);   // Boots gefunden und verwendet
    assert(player3.getInventorySize() == 3);

    assert(player3.useItem(1) == false);  // keine Boots mehr
    assert(player3.getInventorySize() == 3);

    assert(player3.useItem(0) == true);   // erste Gauntlets verwendet
    assert(player3.getInventorySize() == 2);

    assert(player3.useItem(0) == true);   // zweite Gauntlets verwendet
    assert(player3.getInventorySize() == 1);

    assert(player3.useItem(0) == false);  // keine Gauntlets mehr
    assert(player3.getInventorySize() == 1);

    assert(player3.useItem(2) == true);   // Scroll verwendet
    assert(player3.getInventorySize() == 0);

    // ===========================================
    //  TEIL 4: Erweiterbarkeit beweisen
    // ===========================================

    // TrapField: ein neuer Feldtyp, der OHNE Aenderung an
    // bestehendem Code funktioniert — nur eine neue Klasse!
    Field* trap = new TrapField();

    // Sieht aus wie ein leeres Feld (versteckte Falle)
    assert(trap->getSymbol() == '.');

    // Aber: Spieler verliert 1 HP beim Betreten
    Character player4;
    assert(player4.getHealth() == 5);
    trap->onEnter(player4);
    assert(player4.getHealth() == 4);

    delete trap;

    // TrapField funktioniert auch im polymorphen Array
    Field* mixed[3];
    mixed[0] = new WellField();
    mixed[1] = new TrapField();
    mixed[2] = new WellField();

    Character player5;
    for (int i = 0; i < 3; i++) {
        mixed[i]->onEnter(player5);
    }
    // well(+1) + trap(-1) + well(+1) = 6
    assert(player5.getHealth() == 6);

    for (int i = 0; i < 3; i++) {
        delete mixed[i];
    }

    // ===========================================
    //  TEIL 5: GameWorld — Polymorphie in Aktion
    // ===========================================

    // GameWorld verwaltet ein 3x3 Raster aus Field*-Zeigern.
    // setField, getSymbol und handleField delegieren an die
    // Field-Objekte — keine if-Ketten mehr noetig!

    GameWorld gw;  // 3x3, alle EmptyField

    // Standard: alle Felder leer
    assert(gw.getSymbol(0, 0) == '.');
    assert(gw.getSymbol(2, 2) == '.');

    // Felder setzen — polymorph!
    gw.setField(0, 0, new WellField());
    gw.setField(1, 0, new DangerField());
    gw.setField(2, 0, new RelicField());
    gw.setField(0, 1, new TrapField());

    assert(gw.getSymbol(0, 0) == '~');
    assert(gw.getSymbol(1, 0) == '!');
    assert(gw.getSymbol(2, 0) == '*');
    assert(gw.getSymbol(0, 1) == '.');  // Falle sieht aus wie leer

    // handleField delegiert an onEnter() und ersetzt mit EmptyField
    Character gwPlayer;
    gw.handleField(0, 0, gwPlayer);         // Brunnen
    assert(gwPlayer.getHealth() == 6);
    assert(gw.getSymbol(0, 0) == '.');      // jetzt leer

    gw.handleField(1, 0, gwPlayer);         // Gefahr
    assert(gwPlayer.getHealth() == 5);

    gw.handleField(2, 0, gwPlayer);         // Relikt
    assert(gwPlayer.getRelics() == 1);

    gw.handleField(0, 1, gwPlayer);         // Falle
    assert(gwPlayer.getHealth() == 4);

    // GameWorld-Destruktor raeumt alle Field*-Zeiger auf

    std::cout << "Alle Tests bestanden!" << std::endl;
    return 0;
}
