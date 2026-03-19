#include "smartspeaker.h"

SmartSpeaker::SmartSpeaker(std::string name, int stromverbrauch, int volume) : SmartDevice(name, stromverbrauch), volume(volume) {}

void SmartSpeaker::turnOn() {
    std::cout << getName() << " is turnt on with volume: " << this->volume << std::endl;
}

void SmartSpeaker::turnOff() {
    std::cout << getName() << " is turnt off." << std::endl;
}

void SmartSpeaker::setVolume(int volume){
    this->volume = volume;
}