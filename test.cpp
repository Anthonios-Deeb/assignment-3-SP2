#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Catan.hpp"

TEST_CASE("ADD PLAYERS")
{

  SUBCASE("Add 3 players")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3);

    CHECK((*c.getPlayers()).size() == 3);
    c.resetGame();
  }

  SUBCASE("Add 4 players")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);

    CHECK((*c.getPlayers()).size() == 4);
  }

  SUBCASE("Add 2 players with the same name")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 2");
    Player p4("Player 3");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
  }
}

TEST_CASE("CHOOSE STARTING PLAYER")
{
  Player p1("Player 1");
  Player p2("Player 2");
  Player p3("Player 3");
  Player p4("Player 4");

  Catan &c = Catan::getInstance();
  c.addPlayers(&p1, &p2, &p3, &p4);
  c.chooseStartingPlayer();
  c.resetGame();
}

TEST_CASE("END TURN")
{
  Player p1("Player 1");
  Player p2("Player 2");
  Player p3("Player 3");
  Player p4("Player 4");

  Catan &c = Catan::getInstance();
  c.addPlayers(&p1, &p2, &p3, &p4);
  c.chooseStartingPlayer();
  c.endTurn();
  c.resetGame();
}

TEST_CASE("PLACE SETTLEMENT")
{
  SUBCASE("Place Settlement")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    Board *b = c.getBoard();
    b->placeSettlement("EBF");
    c.resetGame();
  }

  SUBCASE("Place Settlement on the same spot")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    Board *b = c.getBoard();
    b->placeSettlement("EBF");
    b->placeSettlement("EBF");
    c.resetGame();
  }

  SUBCASE("Place Settlement on an invalid spot")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    Board *b = c.getBoard();
    b->placeSettlement("KKK");
    c.resetGame();
  }

  SUBCASE("Place settlement near anothoer settlement")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    Board *b = c.getBoard();
    b->placeSettlement("EBF");
    b->placeSettlement("EFJ");
    c.resetGame();
  }
}

TEST_CASE("Place Road")
{
  SUBCASE("Place Road near Settlement")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    Board *b = c.getBoard();
    b->placeSettlement("EBF");
    b->placeRoad("EB");
    c.resetGame();
  }

  SUBCASE("Place road on the same spot")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    Board *b = c.getBoard();
    b->placeSettlement("EBF");
    b->placeRoad("EB");
    b->placeRoad("EB");
    c.resetGame();
  }

  SUBCASE("Place road near nothing")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    Board *b = c.getBoard();
    b->placeRoad("EB");
    c.resetGame();
  }
}

TEST_CASE("Place City")
{
  SUBCASE("Place City on a settlement")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    Board *b = c.getBoard();
    b->placeSettlement("EBF");
    b->placeCity("EBF");
    c.resetGame();
  }

  SUBCASE("Place City without a settlement")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    Board *b = c.getBoard();
    b->placeCity("EBF");
    c.resetGame();
  }

  SUBCASE("Place City on a city")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    Board *b = c.getBoard();
    b->placeSettlement("EBF");
    b->placeCity("EBF");
    b->placeCity("EBF");
    c.resetGame();
  }
}

TEST_CASE("Roll Dice")
{
  Player p1("Player 1");
  Player p2("Player 2");
  Player p3("Player 3");
  Player p4("Player 4");

  Catan &c = Catan::getInstance();
  c.addPlayers(&p1, &p2, &p3, &p4);
  c.chooseStartingPlayer();
  c.getPlayerTurn()->RollDice();
  c.resetGame();
}


TEST_CASE("Trading")
{
  SUBCASE("Trade Resource to Resource")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    c.getPlayerTurn()->tradeResourceToResource(0, ResourceType::BRICK, c.getPlayers()->at(1), ResourceType::IRON, 0);
    c.resetGame();
  }

  SUBCASE("Trade Resource to Resource with invalid amount")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    c.getPlayerTurn()->tradeResourceToResource(0, ResourceType::BRICK, c.getPlayers()->at(1), ResourceType::IRON, 1);
    c.resetGame();
  }
  
  SUBCASE("trade resource to card")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    c.getPlayerTurn()->tradeResourceToCard(0, ResourceType::BRICK, c.getPlayers()->at(1), CardType::KNIGHT);
    c.resetGame();
  }

  SUBCASE("trade card to card")
  {
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Player p4("Player 4");

    Catan &c = Catan::getInstance();
    c.addPlayers(&p1, &p2, &p3, &p4);
    c.chooseStartingPlayer();
    c.getPlayerTurn()->tradeCardToCard(CardType::MONOPOLY, c.getPlayers()->at(1), CardType::KNIGHT);
    c.resetGame();
  }
}

TEST_CASE("Buy Card")
{
  Player p1("Player 1");
  Player p2("Player 2");
  Player p3("Player 3");
  Player p4("Player 4");

  Catan &c = Catan::getInstance();
  c.addPlayers(&p1, &p2, &p3, &p4);
  c.chooseStartingPlayer();
  c.getPlayerTurn()->buyCard();
  c.resetGame();
}

TEST_CASE("Use Card")
{
  Player p1("Player 1");
  Player p2("Player 2");
  Player p3("Player 3");
  Player p4("Player 4");

  Catan &c = Catan::getInstance();
  c.addPlayers(&p1, &p2, &p3, &p4);
  c.chooseStartingPlayer();
  c.getPlayerTurn()->useCard(CardType::KNIGHT);
  c.resetGame();
}