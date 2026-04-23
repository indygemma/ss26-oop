#include "host.h"
#include "livestream.h"

int main() {
  Host host;
  host.addStream(new LiveStream("Formula 1", 100, 300));
  return 0;
}
