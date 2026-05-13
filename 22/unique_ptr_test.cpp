#include "UniquePointer.h"
#include "catch_amalgamated.hpp"

TEST_CASE("UniquePointer has a constructor accepting raw pointers") {
  int *x = new int(200);
  REQUIRE(*x == 200);

  UniquePointer<int> ptr(new int(100));
  REQUIRE(*ptr == 100);
}

TEST_CASE("UniquePointer destructor frees raw memory pointer") {
  int *x = new int(100);
  { UniquePointer<int> ptr(x); }

  REQUIRE_FALSE(*x == 100);
}

TEST_CASE("UniquePointer Move-Constructor works") {
  UniquePointer<int> ptr1(new int(100));
  UniquePointer<int> ptr2(std::move(ptr1));

  REQUIRE_FALSE(ptr1);
  REQUIRE(*ptr2 == 100);
}

TEST_CASE("UniquePointer Move-Assignment works") {
  UniquePointer<int> a(new int(1));
  UniquePointer<int> b(new int(2));

  b = std::move(a);

  REQUIRE_FALSE(a);
  REQUIRE(*b == 1);
}

TEST_CASE("UniquePointer reset") {
  UniquePointer<int> ptr(new int(100));
  ptr.reset(new int(5000));

  REQUIRE(*ptr == 5000);
}

TEST_CASE("UniquePointer release: not owned anymore, no delete") {
  UniquePointer<int> ptr(new int(100));
  int *x = ptr.release();

  REQUIRE_FALSE(ptr);
  REQUIRE(*x == 100);
}

TEST_CASE("UniquePointer swap: between two UniquePointers") {
  UniquePointer<int> a(new int(10));
  UniquePointer<int> b(new int(20));

  a.swap(b);

  REQUIRE(a);
  REQUIRE(b);
  REQUIRE(*a == 20);
  REQUIRE(*b == 10);
}
