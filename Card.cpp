// 3993
// anthoniosdb@gmail.com
#include "Card.hpp"
#include "Catan.hpp"

void Card::setOwner(Player *p)
{
  owner = p;
}

MonopolyCard::MonopolyCard(Player *owner)
{
  this->type = MONOPOLY;
  this->owner = owner;
}

CardType MonopolyCard::getType()
{
  return MONOPOLY;
}

void MonopolyCard::apply()
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

  Catan &catan = Catan::getInstance();           // Get the instance of the game
  vector<Player *>* players = catan.getPlayers(); // Get the players

  // Loop through all the players and take the resource from them and give it to the player who played the card
  int total = 0;
  map<ResourceType, int>* resources;

  for (Player *p : *players)
  {
    if (p != owner) // If the player is not the owner
    {
      resources = p->getResources(); // Get the resources of the player
      for (pair<ResourceType, int> r : *resources)
      {
        if (r.first == getResourceType(resource)) // If the resource is the same as the one the player wants to monopolize
        {
          total += r.second; // Add the amount of the resource to the total
          p->setRescource(r.first, 0); // Set the resource of the player to 0
        }
      }
    }
  }
  owner->setRescource(getResourceType(resource), total); // Give the total amount of the resource to the player who played the card
}

RoadBuildingCard::RoadBuildingCard(Player *owner)
{
  this->type = ROADBUILDING;
  this->owner = owner;
}

CardType RoadBuildingCard::getType()
{
  return ROADBUILDING;
}

void RoadBuildingCard::apply()
{
  Catan &catan = Catan::getInstance();
  catan.setGamePhase(FreeRoadBuilding); // Set the game phase to FreeRoadBuilding
  Board *b = catan.getBoard();         // Get the board
  string coord;                       // The coord of the road
  cout << "You can build 2 roads for Free !!" << endl;
  for (int i = 0; i < 2; i++)
  {
    cout << "where would you like to place the ";
    if (i == 0)
    {
      cout << "first ";
    }
    else
    {
      cout << "second ";
    }
    cout << "road: ";

    cin >> coord; // Get the coord of the road
    while (b->placeRoad(coord) == false) // check if the road placed successfully if not ask the player to enter another coord
    {
      cout << "Please enter another road coord: ";
      cin >> coord;
    }
  }
  catan.setGamePhase(INPROCESS);
  return;
}

YearOfPlentyCard::YearOfPlentyCard(Player *owner)
{
  this->type = YEAROFPLENTY;
  this->owner = owner;
}

CardType YearOfPlentyCard::getType()
{
  return YEAROFPLENTY;
}

void YearOfPlentyCard::apply()
{
  string resource;
  cout << "You can take 2 resources of your choice" << endl;

  for (int i = 0; i < 2; i++)
  {
    cout << "Choose your ";

    if (i == 0)
    {
      cout << "first ";
    }
    else
    {
      cout << "second ";
    }
    cout << "resource: ";
    
    cin >> resource;
    while (getResourceType(resource) == NONE) // Check if the resource is valid
    {
      cout << "Invalid resource. Please enter a valid resource:";
      cin >> resource;
    }
    owner->setRescource(getResourceType(resource), 1); // Give the player the resource
  }
}

KnightCard::KnightCard(Player *owner)
{
  this->type = KNIGHT;
  this->owner = owner;
}

CardType KnightCard::getType()
{
  return KNIGHT;
}

void KnightCard::apply()
{
  cout << "You have played a Knight Card" << endl;
  return;
}


VictoryPointCard::VictoryPointCard(Player *owner)
{
  this->type = VICTORYPOINT;
  this->owner = owner;
}

CardType VictoryPointCard::getType()
{
  return VICTORYPOINT;
}

void VictoryPointCard::apply()
{
  owner->addPoints(1);
}