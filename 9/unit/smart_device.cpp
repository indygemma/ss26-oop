#include "smart_device.h"

SmartDevice::SmartDevice(std::string name, int power_consumption)
    : name(name), power_consumption(power_consumption) {}

void SmartDevice::restart() {
  turnOff();
  turnOn();
}
