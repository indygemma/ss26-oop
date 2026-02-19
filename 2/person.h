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
  ~Person();
  void setAlter(int x);
  void introduce() const;
};

#endif
