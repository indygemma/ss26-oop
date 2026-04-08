#include <iostream>
using namespace std;

template <typename T> // Standard Template
T twice(T n) {
  return n + n;
}

template <> // Spezialisierung für C-Strings
const char *twice(const char *n) {
  const int length = 2 * strlen(n) + 1;
  char *nn = new char[length];
  strcpy(nn, n);
  strcat(nn, n);
  return nn;
}

int main() {
  cout << twice(5) << endl;
  cout << twice("hello") << endl;
  cout << twice(string("hello"));
  return 0;
}
