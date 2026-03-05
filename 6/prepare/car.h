#ifndef __CAR_H__
#define __CAR_H__

#include <string>

class Car {
private:
  std::string name;
  static int counter; // Klassenvariable

public:
  Car(std::string name);
  ~Car();

  static int count(); // Klassenmethode
};

#endif
