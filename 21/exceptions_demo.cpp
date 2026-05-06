#include <exception>
#include <iostream>
#include <stdexcept>

class ValueDoesNotMatchWorldMinedValues : public std::exception {
public:
  const char *what() const noexcept { return "incompatible values"; }
};

void allocate_new_player() {
  throw std::runtime_error("Could not allocate player due insufficient RAM");
}

class World {
private:
  int x;
  int y;

public:
  World(int x, int y) : x(x), y(y) {}
  void run() {
    // allocate_new_player();
    throw std::runtime_error("Something bad happened");
    throw std::range_error("wrong value");
    // throw std::invalid_argument();
    throw ValueDoesNotMatchWorldMinedValues();
    return;
  }
  void restart() {
    // TODO: re-create world
    // TODO: run()
    std::cout << "RESTARTING THE WORLD!" << std::endl;
  }
};

int main() {
  World w = World(5, 5);
  try {
    // world.addPlayer()
    w.run();
  } catch (std::runtime_error &e) {
    std::cout << "A runtime_error exception message: " << e.what() << std::endl;
  } catch (ValueDoesNotMatchWorldMinedValues &e) {
    std::cout << "WARNING: mined values do not match" << std::endl;
    std::cout << "Restarting the world" << std::endl;
    w.restart();
  }

  return 0;
}
