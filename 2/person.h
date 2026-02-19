// include guards
#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

class Person {
  // attributen
private:
  std::string name;
  int *alter;
  int groesse;

public:
  // verhalten

  // Konstruktor = Klassename = Funktionsname
  Person(std::string name, int alter, int groesse);
  Person(const Person &other); // Copy Constructor

  ~Person();
  void setAlter(int x);
  int getAlter() const;
  int getGroesse() const;
  void introduce() const;
};

#endif
