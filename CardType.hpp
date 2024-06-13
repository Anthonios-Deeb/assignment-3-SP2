// 3993
// anthoniosdb@gmail.com
#ifndef CARDTYPE_HPP
#define CARDTYPE_HPP

#include <string>
using namespace std;

enum CardType
{
  MONOPOLY,
  ROADBUILDING,
  YEAROFPLENTY,
  KNIGHT,
  VICTORYPOINT,
  NOCARDTYPE
};

string getCardName(CardType resource);



#endif // CARDTYPE_HPP