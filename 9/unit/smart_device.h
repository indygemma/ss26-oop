#ifndef __SMART_DEVICE_H__
#define __SMART_DEVICE_H__

#include <string>

class SmartDevice {
protected:
  std::string name;
  int power_consumption;

public:
  SmartDevice(std::string name, int power_consumption);
  virtual ~SmartDevice();
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
  void restart();
};

#endif
