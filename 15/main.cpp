#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<vector<vector<int>>> world;
  for (int x = 0; x < 5; x++) {
    world.reserve(5);
    for (int y = 0; y < 5; y++) {
      world[x].reserve(5);
      for (int z = 0; z < 10; z++) {
        world[x][y].reserve(10);
        world[x][y][z] = 10;
      }
    }
  }

  for (int x = 0; x < 5; x++) {
    // world.reserve(10);
    for (int y = 0; y < 5; y++) {
      // world[z].reserve(5);
      for (int z = 0; z < 10; z++) {
        // world[z][y].reserve(5);
        cout << world[x][y][z] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
