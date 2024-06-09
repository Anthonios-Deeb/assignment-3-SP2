#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include <iostream>
#include "Recoureces.hpp"

using namespace std;

class Player
{
public:
    Player();
    Player(string name);
    string getName();
    bool operator==(const Player &p);
    bool operator!=(const Player &p);

    // getters
    int getfreeSettelments() { return freeSettelments; }
    int getfreeRoads() { return freeRoads; }
    int getPoints() { return points; }
    vector<pair<ResourceType, int>> getResources() { return resources; }

    // setters
    void setRescource(ResourceType type, int amount);// set resources for player
    void setfreeRoads();

    int RollDice();

    // cout << player
    friend ostream &operator<<(ostream &os, const Player &player);

private:
    string name;
    int points;
    int freeSettelments = 2;
    int freeRoads = 2;
    vector<pair<ResourceType, int>> resources;

    void deductResource(string type);                         // deduct resources from player after building a road, settlement or city
    bool CanAfford(string type);                              // check if player can afford to build a road, settlement or city
    void decrementfreeRoads() { freeRoads--; }                // decrement free roads after building a road
    void decrementfreeSettelments() { freeSettelments--; }    // decrement free settelments after building a settelment
    void addResource(ResourceType type, bool isCity = false); // add resources to player after rolling the dice
    void addPoints() { points++; }                            // add points to player
};

#endif // PLAYER_HPP