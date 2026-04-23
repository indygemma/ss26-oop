#include "livestream.h"
#include <iostream>
using namespace std;

LiveStream::LiveStream(std::string name, int initialViewers,
                       int viewerFluctuation)
    : Stream(name), viewerCount(initialViewers),
      viewerFluctuation(viewerFluctuation) {}

void LiveStream::start() {
  // TODO: implement Livestream start
  cout << name << " starts with " << viewerCount << " initial viewers." << endl;
}
