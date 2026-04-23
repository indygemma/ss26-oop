#ifndef LIVESTREAM_H
#define LIVESTREAM_H

#include "stream.h"
#include <string>

class LiveStream : public Stream {
private:
  int viewerCount;
  int viewerFluctuation;

public:
  LiveStream(std::string name, int initialViewers, int viewerFluctuation);
  void start() override;
};

#endif
