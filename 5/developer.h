#ifndef __DEVELOPER__
#define __DEVELOPER__

#include "mitarbeiter.h"

class Developer : public Mitarbeiter {
public:
  Developer(int gehalt, std::string name);

  virtual bool work(int hours) override;
};

#endif
