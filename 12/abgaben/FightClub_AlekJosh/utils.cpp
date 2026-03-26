#include "utils.h"
#include "baseAbility.h"
#include "specialAbility.h"
#include <iostream>
using namespace std;

namespace utils {

void generateMonster(unique_ptr<Character> &monsterPtr) {
  int randomNum = (rand() % 3) + 1;
  cout << "You will be fighting one of the 3:" << endl
       << "1. Zombie" << endl
       << "2. Skeleton" << endl
       << "3. Clown" << endl
       << "The random number is: " << randomNum << "! " << endl;

  if (randomNum == 1) {
    monsterPtr = unique_ptr<Character>(new Character(
        "Zombie", unique_ptr<Ability>(new baseAbility("Bite", 10)),
        unique_ptr<Ability>(new specialAbility("Scratch", 20)), 100, 100, 0,
        0));
  } else if (randomNum == 2) {
    monsterPtr = unique_ptr<Character>(new Character(
        "Skeleton", unique_ptr<Ability>(new baseAbility("Bone Smash", 10)),
        unique_ptr<Ability>(new specialAbility("Headbutt", 18)), 100, 100, 0,
        0));
    unique_ptr<Ability> p1(new baseAbility("Bone Smash", 10));
    unique_ptr<Ability> p2(new specialAbility("Headbutt", 18));
  } else if (randomNum == 3) {
    monsterPtr = unique_ptr<Character>(new Character(
        "Clown", unique_ptr<Ability>(new baseAbility("Poison", 12)),
        unique_ptr<Ability>(new specialAbility("Confusion", 13)), 100, 100, 0,
        0));
  }
}

} // namespace utils
