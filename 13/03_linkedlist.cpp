#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

template <typename T> class LinkedList {

public:
  LinkedList() { head = nullptr; }
  virtual ~LinkedList() {
    // TODO: lösche alle Nodes
  }

  void addFirst(T value) { head = createNode(value, head); }

  void addLast(T value) {
    Node *newNode = createNode(value, nullptr);
    // TODO: insert into last position
    Node *next = head;
    while (next->next) {
      next = next->next;
    }
    next->next = newNode;
  }

  void print() {
    // TODO: gib values aller Nodes aus
  }

  T pop() {
    // TODO: actually delete head
    Node *tmp = head;
    if (head->next != nullptr) {
      head = head->next;
    }

    // TODO: check next is not nullptr
    T value = tmp->value;
    delete tmp;
    return value;
  }

  // T operator[](int)
  T operator[](int index) {
    Node *next = head;
    int idx = 0;
    while (next != nullptr) {
      if (idx == index) {
        return next->value;
      }
      next = next->next;
      idx++;
    }
    return head->value;
  }

private:
  struct Node {
    T value;
    Node *next;
  };
  Node *head;

private:
  Node *createNode(T value, Node *next) {
    Node *newHead = new Node();
    newHead->value = value;
    newHead->next = next;
    return newHead;
  }
};

int main() {
  LinkedList<int> intList;
  intList.addFirst(3); // 1
  intList.addFirst(2); // 0
  intList.addLast(6);
  intList.print();
  // DONE: int operator[](int, int)
  assert(intList[0] == 2);
  assert(intList[1] == 3);
  // TODO:
  assert(intList[2] == 6);
  // DONE
  assert(2 == intList.pop());
  assert(3 == intList.pop());
  LinkedList<string> stringList;
  stringList.addFirst("World");
  stringList.addFirst("Hello");
  stringList.addLast("test");
  stringList.print();
  // DONE: string operator[](string, int)
  assert(stringList[0] == "Hello");
  assert(stringList[1] == "World");
  assert(stringList[2] == "test");
  // DONE
  assert("Hello" == stringList.pop());
  assert("World" == stringList.pop());
  return 0;
}
