#include "livestream.h"
#include <iostream>
using namespace std;

LiveStream::LiveStream(std::string name, int initialViewers,
                       int viewerFluctuation)
    : Stream(name), viewerCount(initialViewers),
      viewerFluctuation(viewerFluctuation) {}

void LiveStream::start() {
  // DONE: implement Livestream start
  cout << name << " starts with " << viewerCount << " initial viewers." << endl;
  size_t i = 0;
  size_t maxViewerCount = viewerCount;
  while (viewerCount > 0) {
    cout << name << "running with " << viewerCount << " active viewers."
         << endl;
    viewerCount = viewerCount + viewerFluctuation - i;
    if (viewerCount > maxViewerCount) {
      maxViewerCount = viewerCount;
    }
    i++;
  }
  cout << name << " ended with a maximum of " << maxViewerCount
       << " concurrent viewers." << endl;
}
