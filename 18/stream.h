#ifndef STREAM_H
#define STREAM_H

#include <string>

class Stream {
private:
  std::string name;

public:
  Stream(std::string name);
  virtual void start() = 0;
};

#endif
