#ifndef ROAD_HPP
#define ROAD_HPP

#include <string>
#include "Player.hpp"

namespace Components
{
  class Road
  {
  public:
    Road(string coord , Player &owner) : coord(coord), owner(owner) {}
    string coord;
    Player owner;
  };
}

#endif // ROAD_HPP