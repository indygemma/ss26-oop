#include <iostream>
using namespace std;

namespace conrad {
void hello() { std::cout << "hello" << std::endl; }
} // namespace conrad

int main() {
  cout << "Hello World\n";
  cout << "Hello 2\n";

  cout << 1 + 2 << endl;

  int input;
  cin >> input;

  cout << "User input: " << input << endl;

  conrad::hello();

  int *new_int = new int;
  *new_int = 0; // initialize mit start value
  *new_int = 10;

  // reserviere 10 int im heap
  int *new_ints = new int[10];
  new_ints[0] = 10;
  new_ints[1] = 11;

  delete new_int;
  delete[] new_ints;

  int *test_array = new int[10];
  for (int i = 0; i < 10; i++) {
    test_array[i] = i;
    cout << "Give me a number: ";
    cin >> test_array[i];
    // cout << endl; // not necessary
    cout << "You entered: " << test_array[i] << endl;
  }

  // cout << new_ints[1] << endl;
  return 0;
}
