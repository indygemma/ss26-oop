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

  UniquePointer(UniquePointer &&other) : ptr(other.ptr) { other.ptr = nullptr; }

  T operator*() { return *ptr; }
  operator bool() const { return ptr != nullptr; }
};

#endif
