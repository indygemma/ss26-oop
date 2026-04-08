#include <iostream>
#include <string>
using namespace std;

template <typename T> class LinkedList {
public:
  LinkedList() { head = nullptr; }
  virtual ~LinkedList() {
    // TODO: lösche alle Nodes
  }
  void addFirst(T value) {
    Node *newHead = new Node();
    newHead->value = value;
    newHead->next = head;
    head = newHead;
  }
  void print() {
    // TODO: gib values aller Nodes aus
  }

private:
  struct Node {
    T value;
    Node *next;
  };
  Node *head;
};

int main() {
  LinkedList<int> intList;
  intList.addFirst(3);
  intList.addFirst(2);
  intList.addLast(6);
  intList.print();
  // TODO: int operator[](int, int)
  assert(intList[2] == 6);
  assert(3 == intList.pop());
  LinkedList<string> stringList;
  stringList.addFirst("World");
  stringList.addFirst("Hello");
  stringList.addLast("test");
  stringList.print();
  // TODO: string operator[](string, int)
  assert(stringList[2] == "test");
  assert("World" == stringList.pop());
  return 0;
}
