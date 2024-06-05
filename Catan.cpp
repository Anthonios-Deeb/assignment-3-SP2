#include "Catan.hpp"

Catan::Catan() : board(), p1(nullptr), p2(nullptr), p3(nullptr), p4(nullptr) {}

Catan &Catan::getInstance()
{
  static Catan instance;
  return instance;
}

Board Catan::getBoard()
{
  return board;
}

void Catan::addPlayers(Player *p1, Player *p2, Player *p3, Player *p4)
{
  this->p1 = p1;
  this->p2 = p2;
  this->p3 = p3;
  this->p4 = p4;
}