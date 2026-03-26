#ifndef WORLDGENERATION_H
#define WORLDGENERATION_H
#include <ctime>  //srand
#include <memory> //uniqueptr
#include <string>
#include <vector>

using namespace std;

#include "Ability.h"
#include "Character.h"
#include "baseAbility.h"
#include "specialAbility.h"

class WorldGeneration {
public:
  WorldGeneration();
  virtual ~WorldGeneration();
  static void pickChar(unique_ptr<Character> &heroPtr);
  void generateMonster(unique_ptr<Character> &monsterPtr);

protected:
private:
  vector<unique_ptr<Character>> heroPtr;
  vector<unique_ptr<Character>> monsterPtr;
};

#endif // WORLDGENERATION_H
