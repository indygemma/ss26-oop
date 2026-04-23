#ifndef HOST_H
#define HOST_H

#include "stream.h"
#include <vector>

class Host {
private:
  std::vector<Stream *> streams;

public:
  Host();
  ~Host();
  void addStream(Stream *stream);
  void startAllStreams();
};

#endif
