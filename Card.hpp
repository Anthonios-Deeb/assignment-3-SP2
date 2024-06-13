// 3993
// anthoniosdb@gmail.com
#ifndef CARD_HPP
#define CARD_HPP
#include <string>
using namespace std;

#include "CardType.hpp"


class Player;

class Card
{
public:
  virtual ~Card() = default;
  virtual void apply() = 0;
  virtual CardType getType() = 0;
  virtual void setOwner(Player *p);

protected:
  CardType type;
  Player *owner;
};

class MonopolyCard : public Card
{
public:
  MonopolyCard(Player *owner);
  void apply() override;
  CardType getType() override;
};

class RoadBuildingCard : public Card
{
public:
  RoadBuildingCard(Player *owner);
  void apply() override;
  CardType getType() override;
};
// will be YearOfPlentyCard.hpp
class YearOfPlentyCard : public Card
{
public:
  YearOfPlentyCard(Player *owner);
  void apply() override;
  CardType getType() override;
};

class KnightCard : public Card
{
public:
  KnightCard(Player *owner);
  void apply() override;
  CardType getType() override;
};

class VictoryPointCard : public Card
{
public:
  VictoryPointCard(Player *owner);
  void apply() override;
  CardType getType() override;
};

#endif // CARD_HPP