#include <cassert>
#include <iostream>

int hello(int x) {
  switch (x) {
  case 10:
    return 6;
  case 5:
    return 5;
  default:
    return 100;
  }
}

int main() {
  // int x = 200;

  // assert-like (using if + print + exit)
  if (hello(10) != 10) {
    std::cout << "assertion failed: hello(10) != 6\n" << std::endl;
    exit(-1);
  }

  assert(hello(10) == 6);
  assert(hello(5) == 5);
  assert(hello(100) == 100);
  return 0;
}
