#ifndef ABILITY_H
#define ABILITY_H
#include <string>
using namespace std;

class Character;

class Ability {
public:
  Ability(string name, int damage);
  virtual ~Ability();

  virtual string getName() const { return name; }
  virtual void execute(Character &source, Character &target) = 0;

protected:
  string name;
  int damage;

private:
};

#endif // ABILITY_H
