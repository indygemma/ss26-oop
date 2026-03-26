#ifndef CHARACTER_H
#define CHARACTER_H
#include "Ability.h"
#include <memory> //for unique ptr
#include <string>
#include <vector>


class Character {
public:
  Character(string name, unique_ptr<Ability> a1, unique_ptr<Ability> a2, int hp,
            int maxhp, int wins, int losses);
  virtual ~Character();

  void takeDmg(int amount);
  void useAbility(int index, Character &opponent);
  string getAbilityName(int index);

  // getters
  string getName() const { return name; }
  int getHealth() const { return hp; }
  bool isAlive() const { return hp > 0; }
  void addWin() { wins++; }
  void addLoss() { losses++; }
  int getWins() { return wins; }

protected:
  string name;
  int hp;
  int maxhp;
  int wins;
  int losses;
  vector<unique_ptr<Ability>> abilities;

private:
};

#endif // CHARACTER_H
