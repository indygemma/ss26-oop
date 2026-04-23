#include "host.h"

Host::Host() {}

void Host::addStream(Stream *stream) {
  // DONE: implement addStream
  streams.push_back(stream);
}

void Host::startAllStreams() {
  // DONE: implement startAllStreams
  for (Stream *stream : streams) {
    stream->start();
  }
}
