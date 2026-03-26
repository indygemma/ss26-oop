#include "Ability.h"
#include "Character.h"
#include "baseAbility.h"
#include "specialAbility.h"
#include "utils.h"
#include <iostream>


#include "WorldGeneration.h"
#include <ctime>  //srand
#include <memory> //uniqueptr
#include <string>
#include <vector>

using namespace std;

// try to keep main as small as possible:
// Identify classes that need to interact together and derive methods for that
// interaction.

// int main() {
//   try {
//     GameWorld world;
//     GameMode mode;
//     mode.chooseMode();
//     world.setGameMode(mode);
//     world.chooseCharacter();
//     world.generateEnemy();
//     world.run();
//   } catch (std::exeception e) {
//     cout << "Something happened" << e.to_str() << std::endl;
//   }
//   return 0;
// }

int main() {
  srand(time(0));
  char playAgain = 'y';
  cout << "Welcome to Fight Club!" << endl;
  while (true) {
    cout << "Which game would you like to play?" << endl
         << "(Press 'y' to play Normal 1v1)" << endl
         << "(Press 't' to play 2 Player PVE)" << endl
         << "(Press 'p' to play 2 Player PVP)" << endl
         << "(Press 'n' to exit): ";
    cin >> playAgain;
    cout << "--------------------------------------------------------" << endl;
    if (playAgain == 'n') {
      break;
    }
    while (playAgain == 'y') {
      unique_ptr<Character> hero;
      unique_ptr<Character> monster;
      // Helper method variant: WorldGeneration has static method pickChar
      WorldGeneration::pickChar(hero);
      // Helper function variant: utils namespace (in utils.h) has a function generateMonster
      utils::generateMonster(monster);

      cout << "--------------------------------------------------------"
           << endl;
      cout << "--- BATTLE START: " << hero->getName() << " VS "
           << monster->getName() << " ---" << endl;
      cout << "--------------------------------------------------------"
           << endl;

      while (hero->isAlive() && monster->isAlive()) {
        int choice;
        cout << hero->getName() << " (" << hero->getHealth() << " HP)"
             << " | " << monster->getName() << " (" << monster->getHealth()
             << " HP)" << endl;
        cout << "Choose an ability (1: Base Attack 2: Special Attack): ";
        cin >> choice;

        while (choice != 1 && choice != 2) {
          cout << "invalid choice! pick 1 or 2!" << endl;
          cin >> choice;
        }
        hero->useAbility(choice - 1, *monster);

        int monsterChoice = rand() % 2;
        monster->useAbility(monsterChoice, *hero);
        if (!monster->isAlive()) {
          cout << monster->getName() << " has been defeated!" << endl;
          hero->addWin();
          monster->addLoss();
        }

        if (!hero->isAlive()) {
          cout << hero->getName() << " has been defeated!" << endl;
          hero->addLoss();
          monster->addWin();
        }
      }
      cout << "--- GAME OVER ---" << endl;
      cout << "Stats: " << hero->getName() << " Wins: " << hero->getWins()
           << endl;
      cout << "Fight another monster?" << endl
           << "(Press 'y' to accept)" << endl
           << "(Press 't' to play 2 Player PVE)" << endl
           << "(Press 'p' to play 2 Player PVP)" << endl
           << "(Press 'n' to exit): ";
      cin >> playAgain;
    }

    while (playAgain == 't') {
      cout << "You've entered a team!" << endl;
      unique_ptr<Character> hero;
      unique_ptr<Character> hero2;
      unique_ptr<Character> monster;
      unique_ptr<Character> monster2;
      WorldGeneration::pickChar(hero);
      WorldGeneration::pickChar(hero2);
      utils::generateMonster(monster);
      utils::generateMonster(monster2);

      cout << "--------------------------------------------------------"
           << endl;
      cout << "--- PVE BATTLE START: " << hero->getName() << " and "
           << hero2->getName() << " VS " << monster->getName() << " and "
           << monster2->getName() << " ---" << endl;
      cout << "--------------------------------------------------------"
           << endl;

      while ((hero->isAlive() || hero2->isAlive()) &&
             (monster->isAlive() || monster2->isAlive())) {
        int choice;
        int choiceHit;

        cout << "\n"
             << hero->getName() << " (" << hero->getHealth() << " HP)"
             << " | " << hero2->getName() << " (" << hero2->getHealth()
             << " HP)"
             << " | " << monster->getName() << " (" << monster->getHealth()
             << " HP)"
             << " | " << monster2->getName() << " (" << monster2->getHealth()
             << " HP)" << endl;

        if (hero->isAlive()) {
          cout << "Player 1 turn: ";
          cout << "Choose an ability (1. " << hero->getAbilityName(0)
               << " or 2. " << hero->getAbilityName(1) << "): ";
          cin >> choice;

          while (choice != 1 && choice != 2) {
            cout << "invalid choice! pick 1 or 2! " << endl;
            cin >> choice;
          }

          cout << "Hit monster 1 or 2: ";
          cin >> choiceHit;
          if (choiceHit == 1 && monster->isAlive()) {
            hero->useAbility(choice - 1, *monster);
          } else if (choiceHit == 2 && monster2->isAlive()) {
            hero->useAbility(choice - 1, *monster2);
          } else {
            cout << "Invalid choice! pick 1 or 2! ";
            cin >> choiceHit;
          }
        } else {
          cout << "Player 1 is dead: Skip turn." << endl;
        }

        if (hero2->isAlive()) {
          cout << "Player 2 turn: ";
          cout << "Choose an ability (1. " << hero->getAbilityName(0)
               << " or 2. " << hero->getAbilityName(1) << "): ";
          cin >> choice;

          cout << "Hit monster 1 or 2: ";
          cin >> choiceHit;
          if (choiceHit == 1 && monster->isAlive()) {
            hero2->useAbility(choice - 1, *monster);
          } else if (choiceHit == 2 && monster2->isAlive()) {
            hero2->useAbility(choice - 1, *monster2);
          } else {
            cout << "Invalid choice! pick 1 or 2! ";
            cin >> choiceHit;
          }
        } else {
          cout << "Player 2 is dead: Skip turn." << endl;
        }

        int monsterChoice = rand() % 2;
        int monsterChoiceHit = rand() % 2;

        if (monster->isAlive()) {
          if (monsterChoiceHit == 0 && hero->isAlive()) {
            monster->useAbility(monsterChoice, *hero);
          } else if (monsterChoiceHit == 1 && hero2->isAlive()) {
            monster->useAbility(monsterChoice, *hero2);
          }
        } else {
          cout << "Monster 1 is dead. Skipping turn..." << endl;
        }

        if (monster2->isAlive()) {
          if (monsterChoiceHit == 0 && hero->isAlive()) {
            monster2->useAbility(monsterChoice, *hero);
          } else if (monsterChoiceHit == 1 && hero2->isAlive()) {
            monster2->useAbility(monsterChoice, *hero2);
          }
        } else {
          cout << "Monster 2 is dead. Skipping turn..." << endl;
        }

        if (!monster->isAlive()) {
          cout << monster->getName() << " has been defeated!" << endl;
        }

        if (!monster2->isAlive()) {
          cout << monster2->getName() << " has been defeated!" << endl;
        }

        if (!monster->isAlive() && !monster2->isAlive()) {
          cout << "You win!" << endl;
          hero->addWin();
          hero2->addWin();
        }

        if (!hero->isAlive()) {
          cout << hero->getName() << " has been defeated!" << endl;
        }
        if (!hero2->isAlive()) {
          cout << hero2->getName() << " has been defeated!" << endl;
        }

        if (!hero->isAlive() && !hero2->isAlive()) {
          hero->addLoss();
          hero2->addLoss();
        }
      }
      cout << "--- GAME OVER ---" << endl;
      cout << "Stats: " << hero->getName() << " Wins: " << hero->getWins()
           << " | " << hero2->getName() << " Wins: " << hero2->getWins()
           << endl;
      cout << "Fight another monster?" << endl
           << "(Press 'y' to accept)" << endl
           << "(Press 't' to play 2 Player PVE)" << endl
           << "(Press 'p' to play 2 Player PVP)" << endl
           << "(Press 'n' to exit): ";
      cin >> playAgain;
    }

    while (playAgain == 'p') {
      cout << "You've entered a PVP Duel!" << endl;
      unique_ptr<Character> hero;
      unique_ptr<Character> hero2;
      cout << "Player 1, your turn to pick a Character!" << endl;
      WorldGeneration::pickChar(hero);
      cout << "Player 2, your turn to pick a Character!" << endl;
      WorldGeneration::pickChar(hero2);

      cout << "--------------------------------------------------------"
           << endl;
      cout << "--- PVP BATTLE START: " << hero->getName() << " VS "
           << hero2->getName() << " ---" << endl;
      cout << "--------------------------------------------------------"
           << endl;

      // while both players are alive
      while (hero->isAlive() && hero2->isAlive()) {
        int choice;
        cout << "\n"
             << hero->getName() << " (" << hero->getHealth() << " HP)"
             << " | " << hero2->getName() << " (" << hero2->getHealth()
             << " HP)" << endl;
        cout << "Player 1: Choose an ability (1: Base Attack 2: Special "
                "Attack): ";
        cin >> choice;

        while (choice != 1 && choice != 2) {
          cout << "invalid choice! pick 1 or 2!" << endl;
          cin >> choice;
        }
        hero->useAbility(choice - 1, *hero2);

        if (!hero2->isAlive()) {
          break;
        }
        cout << "Player 2: Choose an ability (1: Base Attack 2: Special "
                "Attack): ";
        cin >> choice;

        cout << "\n"
             << hero->getName() << " (" << hero->getHealth() << " HP)"
             << " | " << hero2->getName() << " (" << hero2->getHealth()
             << " HP)" << endl;

        hero2->useAbility(choice - 1, *hero);

        if (!hero->isAlive()) {
          cout << hero->getName() << " has been defeated!" << endl;
          hero->addLoss();
          hero2->addWin();
        }
        if (!hero2->isAlive()) {
          cout << hero2->getName() << " has been defeated!" << endl;
          hero2->addLoss();
          hero->addWin();
        }
      }
      cout << "--- GAME OVER ---" << endl;
      cout << "Stats: " << hero->getName() << " Wins: " << hero->getWins()
           << endl;
      cout << "Stats: " << hero2->getName() << " Wins: " << hero2->getWins()
           << endl;
      cout << "Fight another monster?" << endl
           << "(Press 'y' to accept)" << endl
           << "(Press 't' to play 2 Player PVE)" << endl
           << "(Press 'p' to play 2 Player PVP)" << endl
           << "(Press 'n' to exit): ";
      cin >> playAgain;
    }
  }
  // char creation

  return 0;
}
