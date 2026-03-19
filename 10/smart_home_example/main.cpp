#include <cassert>
#include "smartdevice.h"
#include "smarthomehub.h"
#include "smartlight.h"
#include "smartspeaker.h"
#include <iostream>
#include <string>
#include <vector>


int main() {
  // TODO: test the hub
  // TODO: instantiate a new SmartLight
  // TODO: connect SmartLight instance to hub
  // TODO: instantiate a new SmartSpeaker
  // TODO: connect SmartSpeaker instance to hub
  // 
  std::vector<SmartDevice*> my_devices;
  my_devices.reserve(100); // 100 devices * sizeof(SmartDevice*)

  SmartDevice *lampe = new SmartLight("Smart Light ULTRA", 120, 100);
  my_devices.push_back(lampe);


  SmartHomeHub meinHub;

  SmartDevice *lautsprecher = new SmartSpeaker("iSpeaker Pro", 50, 120);

  meinHub.addDevice(lampe);
  meinHub.addDevice(lautsprecher);

  meinHub.conncet(lampe);
  meinHub.conncet(lautsprecher);

  SmartDevice* foundDevice = meinHub.findByName("X");
  assert(foundDevice == nullptr);

  foundDevice = meinHub.findByName(lampe->getName());
  if (foundDevice) {
    std::cout << foundDevice->getName() << " found! "
              << foundDevice
              << " original address:"
              << lampe << std::endl;
  }
  assert(foundDevice == lampe);

  foundDevice = meinHub.findByName("iSpeaker Pro");
  assert(foundDevice == lautsprecher);

  delete lampe;
  delete lautsprecher;
  return 0;
}
