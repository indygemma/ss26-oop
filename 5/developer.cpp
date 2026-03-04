#include "developer.h"
#include <iostream>

Developer::Developer(int gehalt, std::string name, std::string language)
    : Mitarbeiter(gehalt, name), language(language) {}

bool Developer::work(int hours) {
  std::cout << "[Developer] working for " << hours << " hours!" << std::endl;
  return true;
}
