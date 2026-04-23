#include "livestream.h"

LiveStream::LiveStream(std::string name, int initialViewers,
                       int viewerFluctuation)
    : Stream(name), viewerCount(initialViewers),
      viewerFluctuation(viewerFluctuation) {}
