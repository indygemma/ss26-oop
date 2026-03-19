#ifndef __SMART_THERMOSTAT_H__
#define __SMART_THERMOSTAT_H__

#include "smartdevice.h"

class SmartThermoStat : public SmartDevice {
private:
  int temperature;

public:
  SmartThermoStat(std::string name, int power_consumption, int temperature);
  void turnOn() override;
  void turnOff() override;
  void setTemperature(int);
};

#endif
