#include "host.h"
#include "livestream.h"

int main() {

  // LiveStream l1("Formula X", 10, 30);
  // l1.start();

  Host host;
  host.addStream(new LiveStream("Formula 1", 100, 300));
  host.addStream(new LiveStream("Formula 2", 10, 50));
  host.addStream(new LiveStream("Formula 3", 20, 30));
  host.addStream(new LiveStream("Formula 4", 30, 500));
  host.addStream(new LiveStream("Formula 5", 40, 30));
  host.addStream(new LiveStream("Formula 6", 50, 10));
  host.addStream(new LiveStream("Formula 7", 60, 20));
  host.addStream(new LiveStream("Formula 8", 70, 50));
  host.startAllStreams();
  return 0;
}
