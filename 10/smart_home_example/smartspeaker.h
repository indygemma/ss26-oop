#ifndef SMARTSPEAKER_H
#define SMARTSPEAKER_H
#include <iostream>
#include "smartdevice.h"
#include <string>

class SmartSpeaker : public SmartDevice {
private:
    int volume;
public:
    SmartSpeaker(std::string, int, int);
    void turnOn() override;
    void turnOff() override;
    void setVolume(int);
};

#endif