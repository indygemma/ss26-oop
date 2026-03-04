#include "developer.h"
#include <iostream>

int main() {
  std::cout << "Developer: A. King" << std::endl;
  Developer dev1(5500, "A. King", "C++");
  dev1.work(15);
  return 0;
}
