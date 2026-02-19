#include "person.h"
#include <iostream>

int main() {
  Person *p1 = new Person("Petra", 20, 170);

  // int new_alter;
  // std::cin >> new_alter;
  // p1->setAlter(new_alter);

  std::cout << "P1 introduces herself: " << std::endl;
  p1->introduce();
  std::cout << "P1.setAlter(-100): " << std::endl;
  p1->setAlter(-100);
  std::cout << "P1 introduces herself: " << std::endl;
  p1->introduce();

  std::cout << "P2 copy constructor from P1: " << std::endl;
  Person p2 = Person(*p1); // Copy Constructor required
  std::cout << "P2 introduces herself: " << std::endl;
  p2.introduce();
  std::cout << "P3 copy constructor from P2: " << std::endl;
  Person p3 = Person(p2);
  std::cout << "P3 introduces herself: " << std::endl;
  p3.introduce();

  std::cout << "P4 constructed via Person('Mark', 25, 180): " << std::endl;
  Person p4 = Person("Mark", 25, 180);
  std::cout << "P4 copy assignment from P2: " << std::endl;
  p4 = p2; // Copy assignment
  std::cout << "P4 introduces himself: " << std::endl;
  p4.introduce();

  delete p1; // destructor call

  std::cout << "P5 constructed via Person('Mark II', 30, 175): " << std::endl;
  Person p5 = Person("Mark II", 30, 175);
  std::cout << "P5 introduces himself: " << std::endl;
  p5.introduce();

  std::cout << "P5 move assignment from P2: " << std::endl;
  p5 = std::move(p2); // Move Assignment

  std::cout << "P5 introduces himself: " << std::endl;
  p5.introduce();

  // std::cout << "P2 introduces herself: " << std::endl;
  // p2.introduce();

  // Operator overloading: operator+ (Has bug for now)
  Person p6 = Person("Something", 20, 160);
  p6 = *p1 + p5;
  std::cout << "P6 introduces himself/herself: " << std::endl;
  p6.introduce();

  // p1.alter = 10;
  // p1.alter = -100;

  return 0;
}
