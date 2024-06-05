#ifndef CITY_HPP
#define CITY_HPP

#include <string>
#include "Player.hpp"

using namespace std;

namespace Components
{
  class City
  {
  public:
    string coord;
    Player *owner;

    City(std::string coord, Player &owner) : coord(coord), owner(&owner)
    {
    }

    // Define copy constructor
    City(const City &other) : coord(other.coord), owner(other.owner)
    {
    }

    // Define copy assignment operator
    City &operator=(const City &other)
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

#endif // CITY_HPP