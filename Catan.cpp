#include "Catan.hpp"

Catan::Catan(){
  board = new Board();
  players = new vector<Player*>();
}

Catan::~Catan()
{
  delete board;
  delete players;
}

Catan &Catan::getInstance()
{
  static Catan instance;
  return instance;
}

Board* Catan::getBoard()
{
  return board;
}

void Catan::addPlayers(Player *p1, Player *p2, Player *p3, Player *p4)
{ 
  players->push_back(p1);
  players->push_back(p2);
  players->push_back(p3);
  if (p4 != nullptr)
  {
    players->push_back(p4);
  }
}