#include <iostream>
#include <string>
using namespace std;

class A {
public:
  // opreator+ required to satisfy templated add definition
  A operator+(const A &other) { return A(); }
};

namespace our_functions {
// int add(int x, int y) { return x + y; }
// double add(double x, double y) { return x + y; }
// string add(string x, string y) { return x + y; }

template <typename T> T add(T x, T y) { return x + y; }
} // namespace our_functions

int main() {
  cout << our_functions::add(1, 2) << endl;
  cout << our_functions::add(1.5, 2.6) << endl;
  cout << our_functions::add<string>("string x", "string y") << endl;
  our_functions::add(A(), A());
}
