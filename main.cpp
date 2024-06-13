// 3993
// anthoniosdb@gmail.com
#include <iostream>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"

int main()
{
  Player p1("Player 1");
  Player p2("Player 2");
  Player p3("Player 3");
  Player p4("Player 4");

  Catan &c = Catan::getInstance();
  c.addPlayers(&p1, &p2, &p3, &p4);
  Board *b = c.getBoard();
  
  c.chooseStartingPlayer();

  Player *player;
  
  b->placeSettlement("EBF");
  b->placeRoad("AB");
  b->placeRoad("EF");
  c.endTurn();

  b->placeSettlement("EBF");
  b->placeSettlement("QNR");
  b->placeRoad("NR");
  c.endTurn();

  b->placeSettlement("HMI");
  b->placeRoad("HM");
  c.endTurn();

  b->placeSettlement("MIN");
  b->placeSettlement("CFG");
  b->placeRoad("FG");
  c.endTurn();

  //////////////////////////
  b->placeSettlement("ROS");
  b->placeRoad("RO");
  c.endTurn();

  b->placeSettlement("Hop");
  b->placeRoad("Ho");
  c.endTurn();

  b->placeSettlement("Dqr");
  b->placeRoad("Dq");
  c.endTurn();

  b->placeSettlement("KLP");
  b->placeRoad("KL");
  c.endTurn();
  ////////////////////////////////////////
  cout << "-------------------" << endl;

  for (int i = 0; i < 4; i++)
  {
    player = c.getPlayerTurn();
    player->RollDice();
    c.endTurn();
  }

  // trading
  cout << "-------------------" << endl;
  player = c.getPlayerTurn();
  player->RollDice();

  //before trade
  cout << *player << endl;
  cout << *c.getPlayers()->at(1) << endl;

  player->tradeResourceToResource(1, ResourceType::WOOL, c.getPlayers()->at(1), ResourceType::WHEAT, 1);
  player->tradeResourceToResource(1, ResourceType::WHEAT, c.getPlayers()->at(1), ResourceType::WOOD, 1);
  player->tradeCardToCard(CardType::KNIGHT, c.getPlayers()->at(1), CardType::MONOPOLY);

  //after trade
  cout << *player << endl;
  cout << *c.getPlayers()->at(1) << endl;
  c.endTurn();

  //buying cards
  cout << "-------------------" << endl;
  player = c.getPlayerTurn();
  player->buyCard();
  player->RollDice();
  player->buyCard();
  c.endTurn();
  return 0;
}