// 3993
// anthoniosdb@gmail.com
#include "Catan.hpp"

#define NUMBER_OF_KNIHGTS 3
#define NUMBER_OF_MONOPOLY 2
#define NUMBER_OF_ROADBUILDING 2
#define NUMBER_OF_YEAROFPLENTY 2
#define NUMBER_OF_VICTORYPOINT 5

Catan::Catan() : running(false)
{
  startGame();
}

void Catan::resetGame()
{
  delete board;       // delete the board
  delete players;     // delete the players
  delete playersTurn; // delete the playersTurn
  delete cards;       // delete the cards 
  startGame();
}

void Catan::startGame()
{
  board = new Board();                 // create a new board
  players = new vector<Player *>();    // create a new vector of players
  playersTurn = new deque<Player *>(); // create a new deque of players
  cards = new vector<Card *>();        // create a new vector of cards
  intiliazeCards();                    // initialize the cards
  gamePhase = SETUP1;                  // set the game phase to the first setup phase

  if (!running) // if the game is not running start the thread to check the winner
  {
    running = true;                       // set the running boolean to true
    winnerCheckThread = thread([this]() { // create a new thread
      while (running)
      {
        checkWinner();
        this_thread::sleep_for(chrono::seconds(1));
      }
    });
  }
}


Catan::~Catan()
{
  running = false;                  // set the running boolean to false
  if (winnerCheckThread.joinable()) // if the thread is joinable join it
  {
    winnerCheckThread.join();
  }
  delete board;       // delete the board
  delete players;     // delete the players
  delete playersTurn; // delete the playersTurn
  delete cards;       // delete the cards
}

void Catan::checkWinner()
{
  for (auto player : *players) // for each player in the players vector
  {
    if (player->getPoints() >= 10) // if the player has 10 or more points
    {
      cout << player->getName() << " has won the game!" << endl; // print the winner
      running = false;                                           // set the running boolean to false
      gamePhase = END;                                           // set the game phase to end
      return;
    }
  }
}

Catan &Catan::getInstance()
{
  static Catan instance;
  return instance;
}

void Catan::intiliazeCards()
{
  for (size_t i = 0; i < NUMBER_OF_KNIHGTS; i++)
  {
    cards->push_back(new KnightCard(nullptr)); // add a new knight card to the cards vector 
  }

  for (size_t i = 0; i < NUMBER_OF_MONOPOLY; i++)
  {
    cards->push_back(new MonopolyCard(nullptr)); // add a new monopoly card to the cards vector
  }

  for (size_t i = 0; i < NUMBER_OF_ROADBUILDING; i++)
  {
    cards->push_back(new RoadBuildingCard(nullptr)); // add a new road building card to the cards vector
  }

  for (size_t i = 0; i < NUMBER_OF_YEAROFPLENTY; i++)
  {
    cards->push_back(new YearOfPlentyCard(nullptr)); // add a new year of plenty card to the cards vector
  }

  for (size_t i = 0; i < NUMBER_OF_VICTORYPOINT; i++)
  {
    cards->push_back(new VictoryPointCard(nullptr)); // add a new victory point card to the cards vector
  }
}

Board *Catan::getBoard()
{
  return board;
}

vector<Player *> *Catan::getPlayers()
{
  return players;
}

vector<Card *> *Catan::getCards()
{
  return cards;
}

GamePhase Catan::getGamePhase()
{
  return gamePhase;
}

void Catan::setGamePhase(GamePhase phase)
{
  gamePhase = phase;
}

void Catan::addPlayers(Player *p1, Player *p2, Player *p3, Player *p4)
{
  
  if (gamePhase != SETUP1) // if the game is not in the first setup phase
  {
    cout << "The game has already started" << endl; // print that the game has already started
    return;
  }

  // check if two players have the same name
  if (p1->getName() == p2->getName() || p1->getName() == p3->getName() || p2->getName() == p3->getName() || (p4 != nullptr && (p1->getName() == p4->getName() || p2->getName() == p4->getName() || p3->getName() == p4->getName())))
  {
    cout << "Two players have the same name" << endl;
    running = false;                                     // set the running boolean to false
    exit(0);                                              // exit the program
  }

  players->push_back(p1);
  players->push_back(p2);
  players->push_back(p3);
  if (p4 != nullptr)
  {
    players->push_back(p4);
  }
}

void Catan::chooseStartingPlayer()
{
  srand(time(0));
  size_t random = rand() % players->size();
  for (size_t i = random; i < players->size(); i++)
  {
    Player *player = players->at(i);
    playersTurn->push_back(player);
  }
  for (size_t i = 0; i < random; i++)
  {
    Player *player = players->at(i);
    playersTurn->push_back(player);
  }
  // if the players are order p2, p4, p3, p1 in the Queue it should be p2 , p4, p3, p1 ,p1 , p3, p4, p2
  for (size_t i = players->size(); i > 0; i--)
  {
    playersTurn->push_back(playersTurn->at(i - 1));
  }

  // print the playing order
  cout << "The playing order is: " << endl;
  for (size_t i = 0; i < players->size(); i++)
  {
    cout << playersTurn->at(i)->getName() << endl;
  }
}

Player *Catan::getPlayerTurn()
{
  return playersTurn->front(); // return the player whose turn it is
}

Player *Catan::endTurn()
{
  if (gamePhase == SETUP1 || gamePhase == SETUP2) // if the game is in the setup phase
  {
    if (setupRounds < players->size()) // if the first setup round is not finished
    {
      playersTurn->push_back(playersTurn->front()); // move the player to the back of the queue
      playersTurn->pop_front();                     // remove the player from the front of the queue
      setupRounds++;                                // increment the number of setup rounds
      if (setupRounds == players->size())           // if the first setup round is finished
      {
        gamePhase = SETUP2; // move to the second setup phase
      }
    }
    else
    {
      playersTurn->pop_front();               // remove the player from the front of the queue
      setupRounds++;                          // increment the number of setup rounds
      if (setupRounds == players->size() * 2) // if the second setup round is finished
      {
        gamePhase = DICEROLL; // move to the dice roll phase
      }
    }
  }
  else if (gamePhase == INPROCESS) // if the game is in the in process phase this where the player can build and trade
  {
    playersTurn->push_back(playersTurn->front()); // move the player to the back of the queue
    playersTurn->pop_front();                     // remove the player from the front of the queue
  }
  return playersTurn->front(); // return the player whose turn it is
}