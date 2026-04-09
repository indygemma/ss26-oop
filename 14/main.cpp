#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Field {
private:
  string fieldname;

public:
  Field(string fieldname) : fieldname(fieldname) {}
  string getName() const { return fieldname; }
};

int main() {
  vector<Field> allfields = {Field("grass"), Field("mud"), Field("grass")};
  vector<int> numbers = {5, 3, 2, 4, 1};
  cout << "sizeof(int): " << sizeof(int) << endl;
  cout << "sizeof(numbers): " << sizeof(numbers) << endl;
  cout << "allfields.size(): " << allfields.size() << endl;
  cout << "numbers.size(): " << numbers.size() << endl;
  numbers.push_back(9);
  numbers.push_back(8);
  numbers.push_back(7);
  numbers.push_back(6);
  cout << "sizeof(numbers) (after 6,7,8,9): " << sizeof(numbers) << endl;
  cout << "allfields.size(): " << allfields.size() << endl;
  cout << "numbers.size(): " << numbers.size() << endl;

  cout << "print all numbers:" << endl;
  for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;

  for (int x : numbers) {
    cout << x << " ";
  }
  cout << endl;

  // for range loop => umgewandelt in iterator for loop
  for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end();
       iter++) {
    cout << *iter << " ";
  }

  for (const Field &field : allfields) {
    cout << field.getName() << endl;
  }

  cout << "=== sorted numbers:" << endl;
  sort(numbers.begin(), numbers.end());

  for (int x : numbers) {
    cout << x << " ";
  }
  cout << endl;

  cout << "=== sorted numbers (reverse):" << endl;
  sort(numbers.begin(), numbers.end(), [](int x, int y) { return x > y; });

  for (int x : numbers) {
    cout << x << " ";
  }
  cout << endl;

  // SUCHEN

  const vector<int>::iterator it = find_if(
      numbers.begin(), numbers.end(), [](int x) { return x >= 5 && x < 9; });
  if (it == numbers.end()) {
    // NOT FOUND
    cout << "Number between 5 and 9 NOT found!" << endl;
  } else {
    // FOUND
    cout << "Number between 5 and 9 found" << endl;
  }

  const vector<int>::iterator it2 =
      find_if(numbers.begin(), numbers.end(), [](int x) { return x > 10; });
  if (it2 == numbers.end()) {
    // NOT FOUND
    cout << "Number > 10 NOT found!" << endl;
  } else {
    // FOUND
    cout << "Number > 10 found" << endl;
  }

  return 0;
}
