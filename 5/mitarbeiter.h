#ifndef __MITARBEITER__
#define __MITARBEITER__

#include <string>

class Mitarbeiter {
private:
  int gehalt; // in euro
protected:
  std::string name;

public:
  Mitarbeiter(int gehalt, std::string name);
  virtual ~Mitarbeiter(); // als Parentklasse, muss Destruktor als virtual
                          // deklariert werden.

  virtual bool work(int hours); // = 0 => there is no implementation => abstract
};

#endif
