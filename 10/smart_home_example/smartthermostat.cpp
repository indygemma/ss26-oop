#include "smartthermostat.h"

void validate_temperature(int new_temp) {
  // validierung von temperature
  if (new_temp < -100 || new_temp > 100) {
    throw std::invalid_argument("temperature outside of range");
  }
}

SmartThermoStat::SmartThermoStat(std::string name, int power_consumption,
                                 int temperature)
    : SmartDevice(name, power_consumption), temperature(temperature) {
  validate_temperature(temperature);
}

void SmartThermoStat::turnOn() {
  std::cout << this->getName()
            << " has been turned on with temperature: " << this->temperature
            << std::endl;
}

void SmartThermoStat::turnOff() {
  std::cout << this->getName()
            << " has been turned off with temperature: " << this->temperature
            << std::endl;
}

void SmartThermoStat::setTemperature(int new_temp) {
  validate_temperature(new_temp);
  this->temperature = new_temp;
}
