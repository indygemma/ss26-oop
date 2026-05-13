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
