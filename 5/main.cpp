#include "developer.h"
#include "marketing.h"
#include <iostream>

int main() {
  std::cout << "Developer: A. King" << std::endl;
  Developer dev1(5500, "A. King", "C++");
  Marketing marketing1(5000, "C. Tibor");
  dev1.work(15);
  marketing1.work(20);

  std::cout << "Sizes of Classes: " << std::endl;
  std::cout << "Mitarbeiter sizeof: " << sizeof(Mitarbeiter) << std::endl;
  std::cout << "Developer sizeof: " << sizeof(Developer) << std::endl;
  std::cout << "Marketing sizeof: " << sizeof(Marketing) << std::endl;

  Developer *dev2 = new Developer(7000, "B. Cross", "F#");

  // SLICING PROBLEM (without pointers)
  std::cout << "Let all work for 40 hours (polymorphic). SLICING PROBLEM"
            << std::endl;
  std::vector<Mitarbeiter> xs = {dev1, marketing1, *dev2};
  for (int i = 0; i < 3; i++) {
    xs[i].work(40);
  }

  // SLICING PROBLEM SOLVED (with pointers)
  std::cout << "Let all work for 40 hours (polymorphic). SLICING PROBLEM SOLVED"
            << std::endl;
  std::vector<Mitarbeiter *> xs1 = {&dev1, &marketing1, dev2};
  for (int i = 0; i < 3; i++) {
    xs1[i]->work(40);
  }

  return 0;
}
