#ifndef __UNIQUE_POINTER_H__
#define __UNIQUE_POINTER_H__

#include <iostream>

template <class T> class UniquePointer {
private:
  T *ptr;

public:
  UniquePointer(T *in_ptr)
      : ptr(in_ptr){

        };
  ~UniquePointer() {
    if (ptr) {
      delete ptr;
      ptr = nullptr;
    }
  }

  // MOVE
  UniquePointer(UniquePointer &&other) : ptr(other.ptr) { other.ptr = nullptr; }
  UniquePointer &operator=(UniquePointer &&other) {
    if (ptr != other.ptr) {
      delete ptr;
      ptr = other.ptr;
      other.ptr = nullptr;
    }
    return *this;
  }

  T operator*() { return *ptr; }
  T *operator->() { return ptr; }
  operator bool() const { return ptr != nullptr; }

  void reset(T *ptr = nullptr) {
    delete this->ptr;
    this->ptr = ptr;
  }

  T *release() {
    T *tmp = ptr;
    ptr = nullptr;
    return tmp;
  }

  void swap(UniquePointer<T> &other) {
    T *tmp = ptr;
    ptr = other.ptr;
    other.ptr = tmp;
  }
};

#endif
