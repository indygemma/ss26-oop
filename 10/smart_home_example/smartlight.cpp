#include "smartlight.h"

SmartLight::SmartLight(std::string name, int stromverbrauch, int helligkeit) : SmartDevice(name, stromverbrauch), helligkeit(helligkeit) {}

void SmartLight::turnOn() {
    std::cout << getName() << " is turnt on with brightness: " << this->helligkeit << std::endl;
}

void SmartLight::turnOff() {
    std::cout << getName() << " is turnt off." << std::endl;
}

void SmartLight::setHelligkeit(int helligkeit){
    this->helligkeit = helligkeit;
}