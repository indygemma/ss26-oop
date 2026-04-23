#include "host.h"

Host::Host() {}

Host::~Host() {
  for (Stream *stream : streams) {
    delete stream;
  }
}

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
