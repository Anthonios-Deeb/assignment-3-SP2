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
    bool CanAfford(string type);
    void deductResource(string type);
    int getfreeSettelments() { return freeSettelments; }
    int getfreeRoads(){ return freeRoads; } 
    void decrementfreeRoads() { freeRoads--; }
    void decrementfreeSettelments() { freeSettelments--; }
    int RollDice();
    void addResource(ResourceType type, bool isCity = false);
    void addPoints() { points++; }

    //cout << player
    friend ostream &operator<<(ostream &os, const Player &player);

  
private:
    string name;
    int points;
    int freeSettelments = 2;
    int freeRoads = 2;
    vector<pair<ResourceType, int>> resources;


};

#endif // PLAYER_HPP