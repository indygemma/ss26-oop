#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H
#include "smartdevice.h"
#include <iostream>
#include <string>

class SmartLight : public SmartDevice {
private:
  int helligkeit;

public:
  SmartLight(std::string, int, int);
  void turnOn() override;
  void turnOff() override;
  void setHelligkeit(int);
};

#endif
