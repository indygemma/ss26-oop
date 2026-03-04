#include "developer.h"
#include "marketing.h"
#include <iostream>

int main() {
  std::cout << "Developer: A. King" << std::endl;
  Developer dev1(5500, "A. King", "C++");
  Marketing marketing1(5000, "C. Tibor");
  dev1.work(15);
  marketing1.work(20);
  return 0;
}
