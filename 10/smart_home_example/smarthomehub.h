#ifndef SMARTHOMEHUB_H
#define SMARTHOMEHUB_H
#include "smartdevice.h"
#include <iostream>
#include <string>
#include <vector>

class SmartHomeHub {
private:
    std::vector <SmartDevice*> devices;
public:
    SmartHomeHub();
    virtual ~SmartHomeHub();
    void addDevice(SmartDevice* d);
    bool conncet(SmartDevice *device);
    bool disconnect(SmartDevice *device);

    SmartDevice* findByName(std::string);
};

#endif