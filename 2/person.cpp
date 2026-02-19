#include "person.h"
#include <iostream>
using namespace std;

// Konstruktor
Person::Person(string name, int alter, int groesse)
    : name(name), alter(nullptr), groesse(groesse) {

  // 1. Aufgabe: Alle Attribute zu initialisieren.
  // 2. Aufgabe: Validierung von Input
  if (name.size() != 0) {
    this->name = "Default Name";
  }

  if (alter > 0) {
    this->alter = new int(alter);
  }

  if (groesse < 0) {
    this->groesse = 1;
  }
}

Person::~Person() {
  // this->name
  delete this->alter;
  // this->groesse
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
