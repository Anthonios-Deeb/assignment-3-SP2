#include <iostream>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"

int main()
{
  Player p1("Player 1");
  Player p2("Player 2");
  Player p3("Player 3");

  Catan &c = Catan::getInstance();
  c.addPlayers(&p1, &p2, &p3);
  Board *b = c.getBoard();

  b->placeSettlement("EBF", p1);

  p1.RollDice();

  cout << p1 << endl;



  return 0;
}