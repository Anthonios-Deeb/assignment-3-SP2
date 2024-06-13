// 3993
// anthoniosdb@gmail.com
#include "Player.hpp"
#include "Catan.hpp"
#include "Card.hpp"
#include "CardType.hpp"

Player::Player(string name) : name(name), points(0), hasLargestArmy(false) // initialize the player with a name and 0 points
{
  resources = new map<ResourceType, int>();
  resources->insert(pair<ResourceType, int>(WOOD, 0));
  resources->insert(pair<ResourceType, int>(BRICK, 0));
  resources->insert(pair<ResourceType, int>(IRON, 0));
  resources->insert(pair<ResourceType, int>(WOOL, 0));
  resources->insert(pair<ResourceType, int>(WHEAT, 0));
  playerCards = new vector<Card *>();
}

Player::~Player()
{
  delete resources;
  delete playerCards;
}

// getters
string Player::getName()
{
  return name;
}

int Player::getPoints()
{
  return points;
}

map<ResourceType, int> *Player::getResources()
{
  return resources;
}

/*
this function is used to add resources to the player after rolling the dice
*/
void Player::addRescource(ResourceType type, bool isCity)
{
  if (isCity)
  {
    (*resources)[type] += 2;

    cout << this->getName() << " has gained 2 " << getResourceName(type) << endl;
  }
  else
  {
    cout << this->getName() << " has gained 1 " << getResourceName(type) << endl;
    (*resources)[type]++;
  }
}

/*
this function is used to add points to the player
*/
void Player::addPoints(int p)
{
  points += p;
}
/*
this function is used to set resources for the player
*/
void Player::setRescource(ResourceType type, int amount)
{
  (*resources)[type] += amount;
}
/*
this function is used to compare two players
*/
bool Player::operator==(const Player &p)
{
  return name == p.name;
}

/*
this function is used to check if the player can afford to build a road, settlement ,city or buy a card
*/
bool Player::CanAfford(string type)
{
  if (type == "Road")
  {
    if ((*resources)[WOOD] < 1 || (*resources)[BRICK] < 1)
    {
      cout << "Not enough resources ";
      return false;
    }
  }
  else if (type == "Settlement")
  {
    if ((*resources)[WOOD] < 1 || (*resources)[BRICK] < 1 || (*resources)[WOOL] < 1 || (*resources)[WHEAT] < 1)
    {
      cout << "Not enough resources ";
      return false;
    }
  }
  else if (type == "City")
  {
    if ((*resources)[WHEAT] < 2 || (*resources)[IRON] < 3)
    {
      cout << "Not enough resources ";
      return false;
    }
  }
  else if (type == "Card")
  {
    if ((*resources)[IRON] < 1 || (*resources)[WOOL] < 1 || (*resources)[WHEAT] < 1)
    {
      cout << "Not enough resources ";
      return false;
    }
  }
  return true;
}

/*
this function is used to deduct resources from the player after building a road, settlement or city
*/
void Player::deductResource(string type)
{
  if (type == "Road")
  {
    (*resources)[WOOD]--;
    (*resources)[BRICK]--;
    return;
  }
  else if (type == "Settlement")
  {
    (*resources)[WOOD]--;
    (*resources)[BRICK]--;
    (*resources)[WOOL]--;
    (*resources)[WHEAT]--;
    return;
  }
  else if (type == "City")
  {
    (*resources)[WHEAT] -= 2;
    (*resources)[IRON] -= 3;
    return;
  }
}

void Player::isSevenRolledTax(int diceRoll)
{
  if (diceRoll != 7)
  {
    return;
  }

  Catan &c = Catan::getInstance();
  vector<Player *> *players = c.getPlayers();

  for (size_t i = 0; i < players->size(); i++)
  {
    // sum the resources of the player
    int sum = 0;
    for (auto resource : *(players->at(i)->getResources()))
    {
      sum += resource.second;
    }

    map<ResourceType, int> *playersRescources = players->at(i)->getResources();

    if (sum > 7)
    {
      cout << endl;
      cout << players->at(i)->getName() << " has more than 7 resources" << endl;
      cout << "Please select half of your resources to discard" << endl;
      int discard = sum / 2;
      while (discard > 0) // loop until the player has discarded half of their resources
      {
        cout << "You have " << discard << " resources left to discard you MUST discard" << endl;

        for (auto it = playersRescources->begin(); it != playersRescources->end(); ++it) // loop through the player's resources
        {
          if (discard == 0) // if the player has discarded half of their resources break the loop
          {
            break;
          }
          if ((*it).second > 0) // if the player has resources of this type ask them how many they want to discard
          {
            cout << "You have " << (*it).second << " " << getResourceName((*it).first) << endl;
            cout << "How many would you like to discard?" << endl;
            int amount;
            cin >> amount; // get the amount the player wants to discard

            // check if the player has that many resources if not ask them to enter another amount and check if he entered a number
            while (amount > (*it).second || amount < 0 || amount > discard) 
            {
              if (amount < 0) // check if the player entered a negative number
              {
                cout << "You cannot enter a negative number" << endl;
              }
              else if (amount > discard) // check if the player entered more resources than they need to discard
              {
                cout << "You must discard " << discard << " resources" << endl;
              }
              else
              {
                cout << "You do not have that many resources" << endl;
              }
              cout << "How many would you like to discard?" << endl;
              cin >> amount;
            }
            (*it).second -= amount;
            cout << "You have " << (*it).second << " " << getResourceName((*it).first) << " left" << endl;
            discard -= amount;
          }
        }
      }
    }
  }
}

/*
this function is used to roll the dice and give resources to players
*/
int Player::RollDice()
{
  if (Catan::getInstance().getGamePhase() == SETUP1 || Catan::getInstance().getGamePhase() == SETUP2)
  {
    cout << "You cannot roll the dice during the setup phase" << endl;
    return 0;
  }
  // Generate a random number between 1 and 12 and change the seed
  random_device rd;

  // Use the time since epoch as a seed
  auto seed = chrono::system_clock::now().time_since_epoch().count();
 mt19937 gen(seed);

  // Define a uniform integer distribution in the range 1-6
  std::uniform_int_distribution<> dis(1, 6);

  // Roll two dice
  int diceRoll = dis(gen) + dis(gen);

  cout << this->getName() << " has rolled a " << diceRoll << endl;

  isSevenRolledTax(diceRoll);

  Catan &c = Catan::getInstance();
  Board *b = c.getBoard();

  vector<HexTile> *hexTiles = b->getHexTiles();
  vector<Settlement> *settlements = b->getSettlements();

  for (size_t i = 0; i < settlements->size(); i++)
  {
    string coord = settlements->at(i).getCoord();
    Player *owner = settlements->at(i).getOwner();
    char hextile1 = coord[0]; // Get the hextile that the settlement is near
    char hextile2 = coord[1]; // Get the hextile that the settlement is near
    char hextile3 = coord[2]; // Get the hextile that the settlement is near

    for (size_t j = 0; j < hexTiles->size(); j++) // Dereference the pointer to the hexTiles vector
    {
      if (hexTiles->at(j).getCoord() == hextile1 || hexTiles->at(j).getCoord() == hextile2 || hexTiles->at(j).getCoord() == hextile3) // Check if the settelment is near a hextile
      {
        if (hexTiles->at(j).getNumber() == diceRoll) // Check if the number on the hextile is equal to the dice roll
        {
          owner->addRescource(hexTiles->at(j).getResource()); // Add the resource to the player
        }
      }
    }
  }
  // set the game phase to INPROCESS
  c.setGamePhase(INPROCESS);
  return diceRoll;
}

/*
this function is used to check if the player has the largest army
if the player has the largest army they get 2 points
if he loses the largest army he loses 2 points
*/
void Player::checkLargestArmy()
{
  int knightCount = 0;
  for (size_t i = 0; i < playerCards->size(); i++)
  {
    if (playerCards->at(i)->getType() == KNIGHT)
    {
      knightCount++;
    }
  }

  if (knightCount >= 3)
  {
    if (hasLargestArmy == false)
    {
      hasLargestArmy = true;
      addPoints(2);
    }
  }
  else
  {
    if (hasLargestArmy == true)
    {
      hasLargestArmy = false;
      addPoints(-2);
    }
  }
}

Card *Player::drawCard()
{
  Catan &c = Catan::getInstance();
  vector<Card *> *cards = c.getCards();  // get the cards vector from the Catan instance
  int random = rand() % cards->size();   // generate a random numebr between 0 and the length of the cards vector
  Card *card = cards->at(random);        // get the card at the random index
  cards->erase(cards->begin() + random); // remove the card from the vector
  card->setOwner(this);                  // set the owner of the card to the player
  return card;
}

void Player::buyCard()
{
  Catan &c = Catan::getInstance();
  if (c.getGamePhase() == SETUP1 || c.getGamePhase() == SETUP2)
  {
    cout << "You cannot buy a card during the setup phase" << endl;
    return;
  }

  if (CanAfford("Card") == false) // check if the player can afford to buy a card
  {
    cout << "You cannot afford to buy a card" << endl;
    return;
  }

  Card *card = drawCard(); // draw a card

  cout << this->name << " bought a card" << endl;

  playerCards->push_back(card); // add the card to the player's cards
  checkLargestArmy();           // check if the player has the largest army

  // deduct the resources from the player
  resources->at(IRON)--;
  resources->at(WOOL)--;
  resources->at(WHEAT)--;
}

void Player::useCard(CardType type)
{
  Catan &c = Catan::getInstance();
  for (size_t i = 0; i < playerCards->size(); i++) // loop through the player's cards
  {
    if (playerCards->at(i)->getType() == type) // check if the card type is the same as the type passed in
    {
      playerCards->at(i)->apply();                 // apply the card
      if (playerCards->at(i)->getType() != KNIGHT) // check if the card is not a knight card
      {
        Card *card = playerCards->at(i);              // get the card
        card->setOwner(nullptr);                      // set the owner of the card to null
        c.getCards()->push_back(card);                // add the card to the cards vector
        playerCards->erase(playerCards->begin() + i); // remove the card from the player's cards
      }

      c.endTurn(); // end the turn
      return;
    }
  }
  cout << "You do not have a this type of card" << endl;
}

// Trading

/*
this function is used to trade resources to a resources with another player
*/

void Player::tradeResourceToResource(int giveAmount, ResourceType giveType, Player *p, ResourceType getType, int amount)
{
  if (GamePhase::DICEROLL == Catan::getInstance().getGamePhase())
  {
    cout << "You cannot trade you have not rolled the dice yet" << endl;
    return;
  }

  if (this == p) // check if the player is trying to trade with themselves
  {
    cout << "You cannot trade with yourself" << endl;
    return;
  }

  if ((*resources)[giveType] < giveAmount) // check if the player has enough resources to trade
  {
    cout << this->getName() << " does not have enough resources to trade" << endl;
    return;
  }

  map<ResourceType, int> *othersResources = p->getResources(); // get the other player's resources

  if ((*othersResources)[getType] < amount) // check if the other player has enough resources to trade
  {
    cout << p->getName() << " does not have enough resources to trade" << endl;
    return;
  }

  (*resources)[giveType] -= giveAmount;       // remove the resources from the player
  (*resources)[getType] += amount;            // add the resources to the player
  (*othersResources)[getType] -= amount;      // remove the resources from the other player
  (*othersResources)[giveType] += giveAmount; // add the resources to the other player
}

/*
this function is used to trade resources to a card with another player
*/
void Player::tradeResourceToCard(int giveAmount, ResourceType giveType, Player *p, CardType type)
{
  if (GamePhase::DICEROLL == Catan::getInstance().getGamePhase())
  {
    cout << "You cannot trade you have not rolled the dice yet" << endl;
    return;
  }

  if (this == p) // check if the player is trying to trade with themselves
  {
    cout << "You cannot trade with yourself" << endl;
    return;
  }

  if ((*resources)[giveType] < giveAmount) // check if the player has enough resources to trade
  {
    cout << this->getName() << " does not have enough resources to trade" << endl; // print an error message
    return;
  }

  if (p->playerCards->size() == 0) // check if the other player has any cards
  {
    cout << p->getName() << " does not have any cards to trade" << endl; // print an error message
    return;
  }

  for (size_t i = 0; i < p->playerCards->size(); i++) // loop through the other player's cards
  {
    if (p->playerCards->at(i)->getType() == type) // check if the player has the card they want to trade for
    {
      this->playerCards->push_back(p->playerCards->at(i));         // add the card to the player's cards
      (*resources)[giveType] -= giveAmount;                        // remove the resources from the player
      p->playerCards->erase(p->playerCards->begin() + i);          // remove the card from the other player's cards
      map<ResourceType, int> *othersResources = p->getResources(); // get the other player's resources
      (*othersResources)[giveType] += giveAmount;                  // add the resources to the other player
      p->checkLargestArmy();                                       // check if the other player has the largest army or lost it after trading the card
      this->checkLargestArmy();                                    // check if the player has the largest army or lost it after trading the card
      return;
    }
  }
  cout << p->getName() << " does not have the card you are looking for" << endl; // print an error message
}

/*
this function is used to trade cards with another player
*/
void Player::tradeCardToCard(CardType giveType, Player *p, CardType getType)
{
  if (GamePhase::DICEROLL == Catan::getInstance().getGamePhase())
  {
    cout << "You cannot trade you have not rolled the dice yet" << endl;
    return;
  }

  if (this == p) // check if the player is trying to trade with themselves
  {
    cout << "You cannot trade with yourself" << endl;
    return;
  }

  if (playerCards->size() == 0)
  {
    cout << this->getName() << " does not have any cards to trade" << endl;
    return;
  }

  if (p->playerCards->size() == 0)
  {
    cout << p->getName() << " does not have any cards to trade" << endl;
    return;
  }

  for (size_t i = 0; i < playerCards->size(); i++)
  {
    if (playerCards->at(i)->getType() == giveType) // check if the player has the card they want to trade
    {
      for (size_t j = 0; j < p->playerCards->size(); j++) // loop through the other player's cards
      {
        if (p->playerCards->at(j)->getType() == getType) // check if the other player has the card they want to trade for
        {
          p->playerCards->push_back(playerCards->at(i));      // add the card to the other player's cards
          playerCards->erase(playerCards->begin() + i);       // remove the card from the player's cards
          playerCards->push_back(p->playerCards->at(j));      // add the other player's card to the player's cards
          p->playerCards->erase(p->playerCards->begin() + j); // remove the other player's card from their cards
          this->checkLargestArmy();                           // check if the player has the largest army or lost it after trading the card
          p->checkLargestArmy();                              // check if the other player has the largest army or lost it after trading the card
          return;
        }
      }
    }
  }
  cout << "You do not have the card you are looking for" << endl;
}

/*
this function is used to trade cards with another player
*/
void Player::tradeCardToResource(CardType giveType, Player *p, ResourceType type, int amount)
{
  p->tradeResourceToCard(amount, type, this, giveType); // call the tradeResourceToCard function on the other player
}

ostream &operator<<(ostream &os, const Player &player)
{
  os << player.name << " has " << player.points << " points" << endl;
  os << "Resources: " << endl;
  for (auto resource : *(player.resources))
  {
    os << getResourceName(resource.first) << ": " << resource.second << endl;
  }
  os << "Cards: " << endl;
  int knightCount = 0;
  int monopolyCount = 0;
  int roadBuildingCount = 0;
  int yearOfPlentyCount = 0;
  int victoryPointCount = 0;

  for (size_t i = 0; i < player.playerCards->size(); i++)
  {
    switch (player.playerCards->at(i)->getType())
    {
    case KNIGHT:
      knightCount++;
      break;
    case MONOPOLY:
      monopolyCount++;
      break;
    case ROADBUILDING:
      roadBuildingCount++;
      break;
    case YEAROFPLENTY:
      yearOfPlentyCount++;
      break;
    case VICTORYPOINT:
      victoryPointCount++;
      break;
    case NOCARDTYPE:
      break;
    }
  }
  if (knightCount > 0)
  {
    os << "number of Knight card: " << knightCount << endl;
  }
  if (monopolyCount > 0)
  {
    os << "number of Monopoly card: " << monopolyCount << endl;
  }
  if (roadBuildingCount > 0)
  {
    os << "number of Road Building card: " << roadBuildingCount << endl;
  }
  if (yearOfPlentyCount > 0)
  {
    os << "number of Year of Plenty card: " << yearOfPlentyCount << endl;
  }
  if (victoryPointCount > 0)
  {
    os << "number of Victory Point card: " << victoryPointCount << endl;
  }
  return os;
}