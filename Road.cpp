// 3993
// anthoniosdb@gmail.com
#include "Road.hpp"

namespace Components
{
  string Road::getCoord() const
  {
    return coord;
  }

  Player *Road::getOwner() const
  {
    return owner;
  }
} // namespace Components