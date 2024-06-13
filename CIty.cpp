// 3993
// anthoniosdb@gmail.com
#include "City.hpp"

namespace Components
{
  City::City(std::string coord, Player &owner) : coord(coord), owner(&owner)
  {
  }

  // getters
  std::string City::getCoord() const
  {
    return coord;
  }

  Player *City::getOwner() const
  {
    return owner;
  }

} // namespace Components