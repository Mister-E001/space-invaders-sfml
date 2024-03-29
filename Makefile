CXX=g++
CXXFLAGS=-std=c++17 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant
OPTIMIZE=-O2
FILES=Window.hpp Window.cpp SpaceInvaders.hpp SpaceInvaders.cpp main.cpp
TARGET=spaceinvaders
LIBRARIES=-l sfml-window -l sfml-graphics -l sfml-system

all: $(TARGET)
$(TARGET): $(FILES)
	$(CXX) $(CXXFLAGS) $(OPTIMIZE) $(FILES) -o $(TARGET) $(LIBRARIES)

debug: $(FILES)
	$(CXX) $(CXXFLAGS) -g $(FILES) -o $(TARGET)-debug $(LIBRARIES)

clean:
	/bin/rm -f $(TARGET)
	/bin/rm -f $(TARGET)-debug
