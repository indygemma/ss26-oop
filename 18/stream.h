#ifndef STREAM_H
#define STREAM_H

#include <string>

class Stream {
protected:
  std::string name;

public:
  Stream(std::string name);
  virtual void start() = 0;
};

#endif
