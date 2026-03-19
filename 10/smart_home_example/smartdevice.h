#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H
#include <iostream>
#include <string>

class SmartDevice {
protected:
    std::string name;
    int stromverbrauch;
public:
    SmartDevice(std::string, int);
    virtual ~SmartDevice();
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    void restart(); 

    std::string getName() const;

};

#endif