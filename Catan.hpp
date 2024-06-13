// 3993
// anthoniosdb@gmail.com
#ifndef CATAN_HPP
#define CATAN_HPP

#include "Board.hpp"
#include "Player.hpp"
#include "Card.hpp"
#include <thread>
#include <atomic>
#include <queue>

using namespace std;

enum GamePhase
{
  SETUP1,
  SETUP2,
  INPROCESS,
  DICEROLL,
  FreeRoadBuilding,
  END
};

class Catan
{

public:
  static Catan &getInstance();
  ~Catan();
  Catan(Catan const &) = delete;
  void operator=(Catan const &) = delete;
  void addPlayers(Player *p1, Player *p2, Player *p3, Player *p4 = nullptr); // Adds a player to the game
  vector<Player *> *getPlayers();                                            // Returns the players
  Board *getBoard();                                                         // Returns the Board
  vector<Card *> *getCards();                                                // Returns the cards
  GamePhase getGamePhase();                                                  // Returns the current game phase
  Player *getPlayerTurn();                                                   // Returns the player whose turn it is
  void chooseStartingPlayer();                                               // Chooses the starting player
  Player *endTurn();                                                         // Moves to the next player's turn
  void setGamePhase(GamePhase phase);                                        // Sets the game phase
  void resetGame();                                                          // resets the game

private:
  Catan();
  Board *board;                 // reference to the board
  vector<Player *> *players;    // reference to all the players
  deque<Player *> *playersTurn; // reference to the players in the order of their turns
  vector<Card *> *cards;        // reference to all the cards
  GamePhase gamePhase;          // current game phase
  size_t setupRounds = 0;       // number of setup rounds

  atomic<bool> running;     // atomic boolean to check if the game is running
  thread winnerCheckThread; // thread to check the winner

  void intiliazeCards(); // initializes the cards
  void checkWinner();    // checks if there is a winner
  
  void startGame();      // starts the game
};

#endif // CATAN_HPP