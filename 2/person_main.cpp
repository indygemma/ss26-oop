#include "person.h"
#include <iostream>

int main() {
  Person *p1 = new Person("Petra", 20, 170);

  int new_alter;
  std::cin >> new_alter;
  p1->setAlter(new_alter);

  p1->introduce();
  p1->setAlter(-100);
  p1->introduce();

  Person p2 = Person(*p1); // Copy Constructor required
  Person p3 = Person(p2);

  Person p4 = Person("Mark", 25, 180);
  p4 = p2; // Copy assignment

  delete p1; // destructor call

  // p1.alter = 10;
  // p1.alter = -100;

  return 0;
}
