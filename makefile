# 324933993
#anthoniosdb@gmail.com
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: demo

demo: Demo.o Catan.o Board.o Player.o Coords.o
	$(CXX) $(CXXFLAGS) -o demo Demo.o Catan.o Board.o Player.o Coords.o

Demo.o: Demo.cpp Catan.hpp Board.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

Catan.o: Catan.cpp Catan.hpp Board.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Catan.cpp

Board.o: Board.cpp Board.hpp Road.hpp Settlement.hpp City.hpp HexTile.hpp Coords.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

Coords.o: Coords.cpp Coords.hpp
	$(CXX) $(CXXFLAGS) -c Coords.cpp

Player.o: Player.cpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

.PHONY: clean all

clean:
	rm -f demo *.o