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
  void placeRoad(string cord, Player &owner);
  void placeSettlement(string cord, Player &owner);
  void placeCity(string cord, Player &owner);
  void printBoardStats();
  vector<Settlement>* getSettlements();
  vector<Road>* getRoads();
  vector<City>* getCities();
  vector<HexTile>* getHexTiles();
  ~Board();

private:
  Coords coords;
  void initializeBoard();
  vector<HexTile>* hexTiles;
  vector<Road>* roads;
  vector<Settlement>* settlements;
  vector<City>* cities;
  bool CanPlaceCity(City city);

  bool CheckSettlementsRules(Settlement settlement);
  bool CheckAdjacentSettlements(Settlement& settlement);
  bool CheckRoadsRules(Road road);

};

#endif // BOARD_HPP