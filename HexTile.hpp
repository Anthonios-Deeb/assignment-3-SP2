// 3993
// anthoniosdb@gmail.com
#ifndef HEX_TILE_HPP
#define HEX_TILE_HPP

#include <string>
#include "Resources.hpp"
using namespace std;

namespace Components
{
  class HexTile
  {
  public:
    HexTile(ResourceType resource = NONE, int number = 0, char coord = 'A', string name = ""); // constructor
    ResourceType getResource();                                                                // get the resource of the tile
    int getNumber();                                                                           // get the number of the tile
    string getName();                                                                          // get the name of the tile
    char getCoord();                                                                           // get the coordinate of the tile

  private:
    ResourceType resource;
    int number;
    string name;
    char coord;
  };
}

#endif // HEX_TILE_HPP