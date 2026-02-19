#include "person.h"
#include <iostream>

int main() {
  Person p1 = Person("Petra", 20, 170);

  int new_alter;
  std::cin >> new_alter;
  p1.setAlter(new_alter);

  p1.introduce();
  p1.setAlter(-100);
  p1.introduce();

  // p1.alter = 10;
  // p1.alter = -100;

  return 0;
}
