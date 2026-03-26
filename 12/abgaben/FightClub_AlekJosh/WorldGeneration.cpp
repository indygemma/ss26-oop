#include "WorldGeneration.h"
#include <iostream>
WorldGeneration::WorldGeneration() {
  // ctor
}

void WorldGeneration::pickChar(unique_ptr<Character> &heroPtr) {
  int choice;
  cout << "Choose between: " << endl
       << "1. Spartan" << endl
       << "2. Assassin" << endl
       << "3. Wizard" << endl;
  cin >> choice;

  if (choice < 1 || choice > 3) {
    cout << "invalid character! Choose again: ";
    cin >> choice;
  }

  if (choice == 1) {
    heroPtr = unique_ptr<Character>(new Character(
        "Spartan", unique_ptr<Ability>(new baseAbility("Slash", 10)),
        unique_ptr<Ability>(new specialAbility("Kick", 20)), 100, 100, 0, 0));
  } else if (choice == 2) {
    heroPtr = unique_ptr<Character>(new Character(
        "Assassin", unique_ptr<Ability>(new baseAbility("Stab", 7)),
        unique_ptr<Ability>(new specialAbility("Kunai Shot", 18)), 100, 100, 0,
        0));
  } else if (choice == 3) {
    heroPtr = unique_ptr<Character>(new Character(
        "Wizard", unique_ptr<Ability>(new baseAbility("Poison", 12)),
        unique_ptr<Ability>(new specialAbility("Fireball", 13)), 100, 100, 0,
        0));
  }
}

void WorldGeneration::generateMonster(unique_ptr<Character> &monsterPtr) {
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

WorldGeneration::~WorldGeneration() {
  // dtor
}
