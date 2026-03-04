#ifndef __MARKETING__
#define __MARKETING__

#include "mitarbeiter.h"

class Marketing : public Mitarbeiter {
public:
  Marketing(int gehalt, std::string name);
  // virtual bool work(int hours) override;
};

#endif
