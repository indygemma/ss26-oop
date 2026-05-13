#include "catch_amalgamated.hpp"

TEST_CASE("UniquePointer has a constructor accepting raw pointers") {
  UniquePointer<int> ptr(new int(100));
  REQUIRE(*ptr == 100);
}

TEST_CASE("UniquePointer destructor frees raw memory pointer") {
  // TODO:
}
