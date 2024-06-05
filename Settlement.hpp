#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include <string>
#include "Player.hpp"

namespace Components
{
  class Settlement
  {
  public:
    std::string coord;
    Player *owner;

    Settlement(std::string coord, Player &owner): coord(coord), owner(&owner)
    {
    }

    // Define copy constructor
    Settlement(const Settlement &other): coord(other.coord), owner(other.owner)
    {
    }

    // Define copy assignment operator
    Settlement &operator=(const Settlement &other)
    {
      if (this != &other)
      {
        coord = other.coord;
        owner = other.owner;
      }
      return *this;
    }
  };

}

#endif // SETTLEMENT_HPP