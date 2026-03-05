#include "animal.h"
#include "bird.h"
#include "cat.h"
#include "dog.h"
#include <cassert>
#include <iostream>

int main() {
  // Zu Beginn sind keine Tiere vorhanden
  assert(Animal::totalAnimals == 0);
  assert(Dog::dogCount == 0);
  assert(Cat::catCount == 0);
  assert(Bird::birdCount == 0);

  // Tiere aufnehmen
  Dog d1("Bello");
  Dog d2("Max");
  Dog d3("Bruno");
  Cat c1("Mimi");
  Bird b1("Tweety");
  Bird b2("Fips");

  // Zähler nach der Aufnahme prüfen
  assert(Animal::totalAnimals == 6);
  assert(Dog::dogCount == 3);
  assert(Cat::catCount == 1);
  assert(Bird::birdCount == 2);

  Animal::census(); // Erste Ausgabe

  // Einige Tiere in einem inneren Block anlegen
  {
    Dog d4("Rex");
    Cat c2("Luna");
    assert(Animal::totalAnimals == 8);
    assert(Dog::dogCount == 4);
    assert(Cat::catCount == 2);
  } // d4 und c2 werden hier automatisch zerstört

  // Nach dem Block müssen die Zähler wieder stimmen
  assert(Animal::totalAnimals == 6);
  assert(Dog::dogCount == 3);
  assert(Cat::catCount == 1);

  Animal::census(); // Zweite Ausgabe — gleich wie die erste

  // getType() prüfen
  assert(d1.getType() == "Hund");
  assert(c1.getType() == "Katze");
  assert(b1.getType() == "Vogel");

  std::cout << "Alle Tests bestanden!" << std::endl;
  return 0;
}
