// 3993
// anthoniosdb@gmail.com
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
    City(std::string coord, Player &owner);

    // getters
    std::string getCoord() const;
    Player *getOwner() const;

  private:
    string coord;
    Player *owner;
  };
}

#endif // CITY_HPP