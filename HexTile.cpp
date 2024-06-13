// 3993
// anthoniosdb@gmail.com
#include "HexTile.hpp"

namespace Components
{
  HexTile::HexTile(ResourceType resource, int number, char coord, string name)
  {
    this->resource = resource;
    this->number = number;
    this->coord = coord;
    this->name = name;
  }

  ResourceType HexTile::getResource()
  {
    return resource;
  }

  int HexTile::getNumber()
  {
    return number;
  }

  string HexTile::getName()
  {
    return name;
  }

  char HexTile::getCoord()
  {
    return coord;
  }
} // namespace Components