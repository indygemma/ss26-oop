#include "mitarbeiter.h"
#include <iostream>

Mitarbeiter::Mitarbeiter(int gehalt, std::string name)
    : gehalt(gehalt), name(name) {
  // TODO: is 'gehalt' a valid number?
  // TODO: is 'name' a valid name?
}

Mitarbeiter::~Mitarbeiter() {}

bool Mitarbeiter::work(int hours) {
  std::cout << "[Mitarbeiter] work() called with hours: " << hours << std::endl;
  return true;
}
