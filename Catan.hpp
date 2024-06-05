#ifndef CATAN_HPP
#define CATAN_HPP

#include "Board.hpp"
#include "Player.hpp"

using namespace std;

class Catan
{

public:
  static Catan &getInstance();

  Catan(Catan const &) = delete;

  void operator=(Catan const &) = delete;

  void addPlayers(Player *p1, Player *p2, Player *p3, Player *p4 = nullptr); // Adds a player to the game

  Board getBoard();                      // Returns the Board
  pair<int, int> chooseStartingPlayer(); // Returns the player number of the starting player
private:
  Catan();

  Board board;
  Player *p1;
  Player *p2;
  Player *p3;
  Player *p4;
};

#endif // CATAN_HPP