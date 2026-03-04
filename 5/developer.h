#ifndef __DEVELOPER__
#define __DEVELOPER__

#include "mitarbeiter.h"
#include <string>

class Developer : public Mitarbeiter {
private:
  std::string language;

public:
  Developer(int gehalt, std::string name, std::string language);

  virtual bool work(int hours) override;
};

#endif
