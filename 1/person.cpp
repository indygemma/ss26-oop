#include "person.h"
#include <iostream>
using namespace std;

// Konstruktor
Person::Person(string x, int y, int z) : name(x), alter(y), groesse(z) {
  // TODO: validierung von parametern
}

void Person::setAlter(int x) {
  // validierung
  if (x < 0) {
    return;
  }

  // x hat einen validen Wert
  alter = x;
}

void Person::introduce() const {
  cout << "Name: " << name << endl;
  cout << "Alter: " << alter << endl;
  cout << "Groesse: " << groesse << endl;
}
