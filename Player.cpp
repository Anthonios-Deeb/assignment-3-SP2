#include "Player.hpp"
#include "Catan.hpp"

Player ::Player()
{
}

Player::Player(string name) : name(name)
{
  points = 0;
  resources = {
      {WOOD, 0},
      {BRICK, 0},
      {WHEAT, 0},
      {WOOL, 0},
      {IRON, 0}};
}

string Player::getName()
{
  return name;
}

bool Player::operator==(const Player &p)
{
  return name == p.name;
}

bool Player::operator!=(const Player &p)
{
  return name != p.name;
}

bool Player::CanAfford(string type)
{
  if (type == "Road")
  {
    if (resources[WOOD].second < 1 || resources[BRICK].second < 1)
    {
      cout << "Not enough resources ";
      return false;
    }
  }
  else if (type == "Settlement")
  {
    if (resources[WOOD].second < 1 || resources[BRICK].second < 1 || resources[WOOL].second < 1 || resources[WHEAT].second < 1)
    {
      cout << "Not enough resources ";
      return false;
    }
  }
  else if (type == "City")
  {
    if (resources[WHEAT].second < 2 || resources[IRON].second < 3)
    {
      cout << "Not enough resources ";
      return false;
    }
  }

  return true;
}

void Player::deductResource(string type)
{
  if (type == "Road")
  {
    resources[WOOD].second--;
    resources[BRICK].second--;
    return;
  }else if (type == "Settlement")
  {
    resources[WOOD].second--;
    resources[BRICK].second--;
    resources[WOOL].second--;
    resources[WHEAT].second--;
    return;
  } else if (type == "City")
  {
    resources[WHEAT].second -= 2;
    resources[IRON].second -= 3;
    return;
  }
}

ostream &operator<<(ostream &os, const Player &player)
{
  os << player.name << " has " << player.points << " points" << endl;
  os << "Resources: " << endl;
  for (auto resource : player.resources)
  {
    os << resource.first << ": " << resource.second << endl;
  }
  return os;
}
// Rolls a dice and returns the result between 1 and 12

int Player::RollDice()
{
  int diceRoll = rand() % 12 + 1;

  Catan &c = Catan::getInstance();
  Board *b = c.getBoard();

  vector<HexTile>* hexTiles = b->getHexTiles();
  vector<Settlement>* settlements = b->getSettlements();

  for (size_t i = 0; i < settlements->size(); i++)
  {
    string coord = settlements->at(i).coord;
    Player* owner = settlements->at(i).owner;
    char hextile1 = coord[0];
    char hextile2 = coord[1];
    char hextile3 = coord[2];

    for (size_t j = 0; j < hexTiles->size(); j++) // Dereference the pointer to the hexTiles vector
    {
      if (hexTiles->at(j).getCoord() == hextile1 || hexTiles->at(j).getCoord() == hextile2 || hexTiles->at(j).getCoord() == hextile3) // Use arrow operator to access elements of the vector
      {
        if (hexTiles->at(j).getNumber() == diceRoll) // Use arrow operator to access elements of the vector
        {
          owner->addResource(hexTiles->at(j).getResource()); // Use arrow operator to access elements of the vector
        }
      }
    }
  }

  return diceRoll;
}

void Player::addResource(ResourceType type, bool isCity)
{
  if (isCity)
  {
    resources[type].second += 2;
  }
  else
  {
    resources[type].second++;
  }
}

void Player::setRescource(ResourceType type, int amount)
{
  resources[type].second = amount;
}

void Player::setfreeRoads()
{
  freeRoads = 2;
}