// 3993
// anthoniosdb@gmail.com
#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include <string>
#include "Player.hpp"

using namespace std;

namespace Components
{
  class Settlement
  {
  public:
    Settlement(std::string coord, Player &owner);
    // Define copy constructor
    Settlement(const Settlement &other);
    // Define copy assignment operator
    Settlement &operator=(const Settlement &other);

    // getters
    string getCoord() const;
    Player *getOwner() const;

  private:
    string coord;
    Player *owner;
  };

}

#endif // SETTLEMENT_HPP