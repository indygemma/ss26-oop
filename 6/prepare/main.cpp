#include "car.h"
#include <iostream>

int main() {

  // erwartet: 0. Car::count() => Klassenmethode
  std::cout << "0. Car count: " << Car::count() << std::endl;

  Car car1("Audi");
  Car car2("BMW");

  // erwartet: 2
  std::cout << "1. Car count: " << Car::count() << std::endl;

  {
    Car car3("Porsche");
    // erwartet: 3
    std::cout << "2. Car count: " << Car::count() << std::endl;
  }

  // erwartet: 2
  std::cout << "3. Car count: " << Car::count() << std::endl;
  return 0;
}
