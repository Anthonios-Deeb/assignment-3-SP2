#include "CardType.hpp"


string getCardName(CardType card)
{
  switch (card)
  {
  case MONOPOLY:
    return "Monopoly";
  case ROADBUILDING:
    return "Road Building";
  case YEAROFPLENTY:
    return "Year of Plenty";
  case KNIGHT:
    return "Knight";
  case VICTORYPOINT:
    return "Victory Point";
  default:
    return "No Card Type";
  }
}