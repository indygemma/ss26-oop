#include "catch_amalgamated.hpp"

int hello(int x) {
  switch (x) {
  case 10:
    return 10;
  case 10000:
    throw std::runtime_error("unknown input");
  default:
    return 100;
  }
}

TEST_CASE("testing hello function") {
  REQUIRE(hello(10) == 10);
  CHECK(hello(10) == 10);
  REQUIRE_THROWS(hello(10000));
}
