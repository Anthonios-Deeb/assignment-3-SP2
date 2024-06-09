#ifndef CARD_HPP
#define CARD_HPP

using namespace std;
enum CardType
{
  Monopoly,
  RoadBuilding,
  YearOfPlenty,
  knight,
  VictoryPoint
};

class Card
{
public:
  Card() = delete;
  virtual CardType getType();
  virtual void activate();

protected:
  CardType type;
  Player *owner;
};

class MonopolyCard : public Card
{
public:
  MonopolyCard();
  void activate();
  CardType getType() override;
};

class RoadBuildingCard : public Card
{
public:
  RoadBuildingCard();
  void activate();
  CardType getType() override;
};

#endif // CARD_HPP