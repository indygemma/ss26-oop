#include "host.h"
#include "livestream.h"

int main() {
  Host host;
  host.addStream(new LiveStream("Formula 1", 100, 300));
  host.addStream(new LiveStream("Formula 2", 10, 50));
  host.startAllStreams();
  return 0;
}
