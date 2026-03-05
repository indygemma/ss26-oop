#include "car.h"

int Car::counter = 0; // initialize Klassenvariable

Car::Car(std::string name) : name(name) { this->counter++; }

Car::~Car() { this->counter--; }

int Car::count() { return counter; }
