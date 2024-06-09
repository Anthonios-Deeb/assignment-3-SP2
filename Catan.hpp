#ifndef CATAN_HPP
#define CATAN_HPP

#include "Board.hpp"
#include "Player.hpp"

using namespace std;

class Catan
{

public:
  static Catan &getInstance();
  ~Catan();
  Catan(Catan const &) = delete;
  void operator=(Catan const &) = delete;
  void addPlayers(Player *p1, Player *p2, Player *p3, Player *p4 = nullptr); // Adds a player to the game
  vector<Player *> getPlayers();          // Returns the players
  Board* getBoard();                      // Returns the Board
  

private:
  Catan();
  Board *board;
  vector<Player*>* players;
};

#endif // CATAN_HPP