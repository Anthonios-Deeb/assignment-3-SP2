// 3993
// anthoniosdb@gmail.com
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <random>
#include <chrono>
#include "Resources.hpp"
#include "CardType.hpp"

using namespace std;

class Card;
class MonopolyCard;
class RoadBuildingCard;
class YearOfPlentyCard;
class KnightCard;
class VictoryPointCard;
class Board;

class Player
{

friend class Card;
friend class MonopolyCard;
friend class RoadBuildingCard;
friend class YearOfPlentyCard;
friend class KnightCard;
friend class VictoryPointCard;
friend class Board;

public:
    Player() = delete;
    ~Player();
    Player(string name);
    bool operator==(const Player &p);

    // getters
    string getName();
    int getPoints();
    map<ResourceType, int> *getResources();

    // methods
    int RollDice();              // roll the dice and give resources to players
    void buyCard();              // buy a card
    void useCard(CardType type); // use a card

    // trade methods
    void tradeResourceToResource(int giveAmount, ResourceType giveType, Player *p, ResourceType getType, int getAmount); // trade resources to a resources with another player
    void tradeResourceToCard(int giveAmount, ResourceType giveType, Player *p, CardType type);                           // trade resources to a card with another player
    void tradeCardToCard(CardType giveType, Player *p, CardType getType);                                                // trade cards with another player
    void tradeCardToResource(CardType giveType, Player *p, ResourceType type, int amount);                               // trade cards with another player

    friend ostream &operator<<(ostream &os, const Player &player);

private:
    string name;
    int points;
    bool hasLargestArmy;
    map<ResourceType, int> *resources;
    vector<Card *> *playerCards;

    Card *drawCard();                                         // draw a card
    void isSevenRolledTax(int diceRoll);                      // check if the dice roll is 7 and apply the tax
    void checkLargestArmy();                                  // check if the player has the largest army
    void addRescource(ResourceType type, bool isCity = false); // add resources to player after rolling the dice
    void addPoints(int p);                                    // add points to player
    void deductResource(string type);                         // deduct resources from player after building a road, settlement or city
    void setRescource(ResourceType type, int amount);         // set resources for player
    bool CanAfford(string type);                              // check if player can afford to build a road, settlement or city
};

#endif // PLAYER_HPP