#include "host.h"
#include "livestream.h"

int main() {

  // LiveStream l1("Formula X", 10, 30);
  // l1.start();

  Host host;
  host.addStream(new LiveStream("Formula 1", 100, 300));
  host.addStream(new LiveStream("Formula 2", 10, 50));
  host.startAllStreams();
  return 0;
}
