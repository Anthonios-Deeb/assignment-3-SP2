// 3993
// anthoniosdb@gmail.com
#ifndef ROAD_HPP
#define ROAD_HPP

#include <string>
#include "Player.hpp"

namespace Components
{
  class Road
  {
  public:
    Road(string coord, Player &owner) : coord(coord), owner(&owner) {}

    // getters
    string getCoord() const;
    Player *getOwner() const;

  private:
    string coord;
    Player *owner;
  };
}

#endif // ROAD_HPP