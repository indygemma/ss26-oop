CXX = g++
CXXFLAGS = -Wall -std=c++17

# Vorher-Version (zum Testen des Ausgangscodes)
vorher: main_vorher.cpp character.cpp field.cpp item.cpp world.cpp
	$(CXX) $(CXXFLAGS) -o vorher main_vorher.cpp character.cpp field.cpp item.cpp world.cpp

# Nachher-Version (Ziel — kompiliert erst nach dem Refactoring)
nachher: main.cpp character.cpp field.cpp item.cpp world.cpp
	$(CXX) $(CXXFLAGS) -o nachher main.cpp character.cpp field.cpp item.cpp world.cpp

clean:
	rm -f vorher nachher

.PHONY: clean
