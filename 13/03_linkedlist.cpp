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
  intList.print();
  LinkedList<string> stringList;
  stringList.addFirst("World");
  stringList.addFirst("Hello");
  stringList.print();
  return 0;
}
