#3993
#anthoniosdb@gmail.com
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
OFILES = main.o Catan.o Board.o Player.o Coords.o HexTile.o Settlement.o Road.o Resources.o CardType.o Card.o City.o
OTEST= test.o Catan.o Board.o Player.o Coords.o HexTile.o Settlement.o Road.o Resources.o Card.o CardType.o City.o

catan: game test

test:	$(OTEST)
	$(CXX) $(CXXFLAGS) -o test $(OTEST)

game: $(OFILES)
	$(CXX) $(CXXFLAGS) -o game $(OFILES)

main.o: main.cpp Catan.hpp Board.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Catan.o: Catan.cpp Catan.hpp Board.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Catan.cpp

Board.o: Board.cpp Board.hpp Road.hpp Settlement.hpp City.hpp HexTile.hpp Coords.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

Coords.o: Coords.cpp Coords.hpp
	$(CXX) $(CXXFLAGS) -c Coords.cpp

Player.o: Player.cpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

HexTile.o: HexTile.cpp HexTile.hpp
	$(CXX) $(CXXFLAGS) -c HexTile.cpp

Settlement.o: Settlement.cpp Settlement.hpp
	$(CXX) $(CXXFLAGS) -c Settlement.cpp

Resources.o: Resources.cpp Resources.hpp
	$(CXX) $(CXXFLAGS) -c Resources.cpp

Card.o: Card.cpp Card.hpp
	$(CXX) $(CXXFLAGS) -c Card.cpp

Road.o: Road.cpp Road.hpp
	$(CXX) $(CXXFLAGS) -c Road.cpp

City.o: City.cpp City.hpp
	$(CXX) $(CXXFLAGS) -c City.cpp

.PHONY: clean catan

clean:
	rm -f game test *.o