#include "Card.hpp"
#include "Catan.hpp"


CardType MonopolyCard::getType()
{
  return Monopoly;
}

void MonopolyCard::activate()
{
  string resource;
  cout << "Which resource would you like to monopolize? " << endl;
  cin >> resource;

  // Check if the resource is valid
  while (getResourceType(resource) == NONE)
  {
    cout << "Invalid resource. Please enter a valid resource:";
    cin >> resource;
  }

  Catan &catan = Catan::getInstance(); // Get the instance of the game
  vector<Player *> players = catan.getPlayers(); // Get the players

  // Loop through all the players and take the resource from them and give it to the player who played the card
  int total = 0;
  vector<pair<ResourceType, int>> resources;
  for (Player *p : players)
  {
    if (p != owner)
    {
      resources = p->getResources();
      for (pair<ResourceType, int> r : resources)
      {
        if (r.first == getResourceType(resource))
        {
          total += r.second;
          p->setRescource(r.first, 0);
        }
      }
      
    }
  }
  owner->setRescource(getResourceType(resource), total);
}

CardType RoadBuildingCard::getType()
{
  return RoadBuilding;
}

void RoadBuildingCard::activate()
{
  owner-> setfreeRoads();
}