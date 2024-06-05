#ifndef HEX_TILE_HPP
#define HEX_TILE_HPP

#include <string>
#include "Recoureces.hpp"
using namespace std;

namespace Components
{
  class HexTile
  {
  public:
    HexTile(ResourceType resource = NONE, int number = 0, char coord = 'A', string name = "") : resource(resource), number(number), name(name), coord(coord) {}
    ResourceType getResource() { return resource; }
    int getNumber() { return number; }
    string getName() { return name; }
    char getCoord() { return coord; }
  private:
    ResourceType resource;
    int number;
    string name;
    char coord;
  };
}

#endif // HEX_TILE_HPP