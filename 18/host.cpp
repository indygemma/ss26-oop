#include "host.h"
#include <thread>

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

void start_stream(Stream *stream) { stream->start(); }

void Host::startAllStreams() {
  // DONE: implement startAllStreams
  std::vector<std::thread> threads;
  for (Stream *stream : streams) {
    threads.push_back(std::thread(start_stream, stream));
  }

  for (size_t i = 0; i < threads.size(); i++) {
    threads[i].join();
  }
}
