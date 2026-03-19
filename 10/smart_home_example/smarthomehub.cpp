#include "smarthomehub.h"

SmartHomeHub::SmartHomeHub() {}

SmartHomeHub::~SmartHomeHub() {}

void SmartHomeHub::addDevice(SmartDevice *d) { devices.push_back(d); }

bool SmartHomeHub::conncet(SmartDevice *dev) {
  dev->turnOn();
  std::cout << "your device has been connceted successfully\n";
  return true;
}

bool SmartHomeHub::disconnect(SmartDevice *dev) {
  dev->turnOff();
  std::cout << "your device has been disconnceted successfully\n";
  return false;
}

SmartDevice *SmartHomeHub::findByName(std::string name) {
  // Traditional for loop
  // for (int i = 0; i < devices.size(); i++) {
  //   SmartDevice *d = devices.at(i); // alternative: devices[i]
  // }

  // range-based for loop
  for (SmartDevice *d : devices) {
    if (d->getName() == name) {
      return d;
    }
  }
  return nullptr;
}
