// 3993
// anthoniosdb@gmail.com
#include "Settlement.hpp"

namespace Components
{
  Settlement::Settlement(std::string coord, Player &owner) : coord(coord), owner(&owner)
  {
  }

  Settlement::Settlement(const Settlement &other) : coord(other.coord), owner(other.owner)
  {
  }

  Settlement &Settlement::operator=(const Settlement &other)
  {
    if (this != &other)
    {
      coord = other.coord;
      owner = other.owner;
    }
    return *this;
  }

  string Settlement::getCoord() const
  {
    return coord;
  }

  Player *Settlement::getOwner() const
  {
    return owner;
  }
} // namespace Components