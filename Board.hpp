// 3993
// anthoniosdb@gmail.com
#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>
#include "HexTile.hpp"
#include "Road.hpp"
#include "Settlement.hpp"
#include "City.hpp"
#include "Coords.hpp"
using namespace std;
using namespace Components;



class Board
{
public:
  Board();
  ~Board();
  bool placeRoad(string cord);          // returns true if road is placed successfully
  bool placeSettlement(string cord);    // returns true if settlement is placed successfully
  bool placeCity(string cord);          // returns true if city is placed successfully
  void printBoardStats();               // prints the informaion about the sttelements, cities, and roads on the board
  vector<Settlement> *getSettlements(); // returns the vector of settlements
  vector<Road> *getRoads();             // returns the vector of roads
  vector<City> *getCities();            // returns the vector of cities
  vector<HexTile> *getHexTiles();       // returns the vector of hexTiles

private:
  Coords coords;
  vector<HexTile> *hexTiles;
  vector<Road> *roads;
  vector<Settlement> *settlements;
  vector<City> *cities;

  void initializeBoard();                           // initializes the board with hexTiles
  bool checkCityRules(City city);                   // checks if the city can be placed on the board
  bool checkSettlementRules(Settlement settlement); // checks if the settlement can be placed on the board
  bool checkRoadRules(Road road);                   // checks if the road can be placed on the board
};

#endif // BOARD_HPP