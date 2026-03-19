#include "smartdevice.h"

SmartDevice::SmartDevice(std::string name, int stromverbrauch)
    : name(name), stromverbrauch(stromverbrauch) {}
SmartDevice::~SmartDevice() {}

void SmartDevice::restart() {
  turnOff();
  turnOn();
}

std::string SmartDevice::getName() const { return name; }
