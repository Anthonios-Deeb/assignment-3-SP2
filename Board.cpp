// 3993
// anthoniosdb@gmail.com
#include "Board.hpp"
#include "Catan.hpp"
#include <iostream>
using namespace std;

void Board::initializeBoard()
{
    hexTiles->push_back(HexTile(IRON, 10, 'A', "Mountains"));
    hexTiles->push_back(HexTile(WOOL, 2, 'B', "Pasture Land"));
    hexTiles->push_back(HexTile(WOOD, 9, 'C', "Forest"));
    hexTiles->push_back(HexTile(WHEAT, 12, 'D', "Fields"));
    hexTiles->push_back(HexTile(BRICK, 6, 'E', "Hills"));
    hexTiles->push_back(HexTile(WOOL, 4, 'F', "Pasture Land"));
    hexTiles->push_back(HexTile(BRICK, 10, 'G', "Hills"));
    hexTiles->push_back(HexTile(WHEAT, 9, 'H', "Fields"));
    hexTiles->push_back(HexTile(WOOD, 11, 'I', "Forest"));
    hexTiles->push_back(HexTile(DESERT, 0, 'J', "DESERT"));
    hexTiles->push_back(HexTile(WOOD, 3, 'K', "Forest"));
    hexTiles->push_back(HexTile(IRON, 8, 'L', "Moutains"));
    hexTiles->push_back(HexTile(WOOD, 8, 'M', "Forest"));
    hexTiles->push_back(HexTile(IRON, 3, 'N', "Moutains"));
    hexTiles->push_back(HexTile(WHEAT, 4, 'O', "Fields"));
    hexTiles->push_back(HexTile(WOOL, 5, 'P', "Pasture Land"));
    hexTiles->push_back(HexTile(BRICK, 5, 'Q', "Hills"));
    hexTiles->push_back(HexTile(WHEAT, 6, 'R', "Fields"));
    hexTiles->push_back(HexTile(WOOL, 11, 'S', "Pasture Land"));
}

Board::Board() : coords()
{
    this->hexTiles = new vector<HexTile>();
    this->roads = new vector<Road>();
    this->settlements = new vector<Settlement>();
    this->cities = new vector<City>();
    initializeBoard();
}

Board::~Board()
{
    delete this->hexTiles;
    delete this->roads;
    delete this->settlements;
    delete this->cities;
}

vector<Settlement> *Board::getSettlements()
{
    return settlements;
}

vector<Road> *Board::getRoads()
{
    return roads;
}

vector<City> *Board::getCities()
{
    return cities;
}

vector<HexTile> *Board::getHexTiles()
{
    return hexTiles;
}

/*
this function is used to check if the settlement can be placed on the board by checking the following rules:
1. check if the coord exists
2. check if the settlement is already taken
3. check if there is a settlement nearby
4. check if there is a road nearby only if the setup phase is over
returns true it passes all the rules and false otherwise
*/
bool Board::checkSettlementRules(Settlement settlement)
{
    string coord = settlement.getCoord();
    if (coords.ifVertexCoordExists(coord) == false) // check if the coord exists
    {
        cout << "There is NO Such Coord" << endl;
        return false;
    }

    Player *owner = settlement.getOwner(); // get the owner of the settlement

    // check if the settlement is already taken
    for (size_t i = 0; i < settlements->size(); i++)
    {
        if (settlements->at(i).getCoord() == settlement.getCoord())
        {
            cout << "SETTLEMENT ALREADY TAKEN !!" << endl;
            return false;
        }
    }

    // check if there is a settlement nearby
    for (size_t i = 0; i < settlements->size(); i++)
    {
        if (coords.isSettlementAdjacent((settlements->at(i).getCoord()), coord))
        {
            cout << "Settlement Can NOT be placed there is another settlement nearby" << endl;
            return false;
        }
    }

    string edge1 = coord.substr(0, 2);                      // get the edges of the vertex
    string edge2 = coord.substr(1, 2);                      // get the edges of the vertex
    string edge3 = edge1.substr(0, 1) + edge2.substr(1, 1); // get the edges of the vertex

    Catan &c = Catan::getInstance();

    if (c.getGamePhase() == INPROCESS) // check if there is a road nearby only if the setup phase is over
    {
        for (size_t i = 0; i < roads->size(); i++)
        {
            // check if there is a road nearby
            if (roads->at(i).getCoord() == edge1 || roads->at(i).getCoord() == edge2 || roads->at(i).getCoord() == edge3)
            {
                Player *roadOwner = roads->at(i).getOwner();
                if (roadOwner == owner)
                {
                    return true;
                }
            }
        }
    }
    else
    {
        return true;
    }

    cout << "Settlement can NOT be placed There is NO adjacent Road" << endl;
    return false;
}

/*
this function is used to place a settlement on the board and uses the function above checkSettlementRules
to check if the settlement can be placed by the Rules that are adrressed in the function above
returns true if the settlement is placed successfully and false otherwise
*/
bool Board::placeSettlement(string coord)
{
    if (GamePhase::DICEROLL == Catan::getInstance().getGamePhase())
    {
        cout << "You cannot Build you have not rolled the dice yet" << endl;
        return false;
    }
    Catan &c = Catan::getInstance();
    Player *player = c.getPlayerTurn();

    Settlement settlement(coord, *player); // create a settlement object
    if (checkSettlementRules(settlement))  // check if the settlement can be placed
    {
        if (c.getGamePhase() == SETUP1 || c.getGamePhase() == SETUP2) // check if the game phase is setup
        {
            cout << player->getName() << " placed a Settlement on the coord " << coord << endl;
            settlements->push_back(settlement); // add the settlement to the vector of settlements
            player->addPoints(1);               // add a point to the player

            if (c.getGamePhase() == SETUP2)
            {
                char hextile1 = coord[0]; // Get the hextile that the settlement is near
                char hextile2 = coord[1]; // Get the hextile that the settlement is near
                char hextile3 = coord[2]; // Get the hextile that the settlement is near

                for (size_t j = 0; j < hexTiles->size(); j++) // Dereference the pointer to the hexTiles vector
                {
                    if (hexTiles->at(j).getCoord() == hextile1 || hexTiles->at(j).getCoord() == hextile2 || hexTiles->at(j).getCoord() == hextile3) // Check if the settelment is near a hextile
                    {
                        player->addRescource(hexTiles->at(j).getResource()); // Add the resource to the player
                    }
                }
            }

            return true;
        }
        else if (player->CanAfford("Settlement") && c.getGamePhase() == INPROCESS) // check if the player can afford the settlement
        {
            cout << player->getName() << " placed a Settlement on the coord " << coord << endl;
            player->deductResource("Settlement"); // deduct the resources from the player
            settlements->push_back(settlement);   // add the settlement to the vector of settlements
            player->addPoints(1);                 // add a point to the player
            return true;
        }
    }
    return false;
}

/*
this function is used to check if the road can be placed on the board by checking the following rules:
1. check if the coord exists
2. check if the road is already taken
3. check if there is a settlement nearby
4. check if there is a road nearby
returns true it passes all the rules and false otherwise
*/
bool Board::checkRoadRules(Road road)
{
    string coord = road.getCoord();
    if (coords.ifEdgeCoordExists(coord) == false) // check if the coord exists
    {
        cout << "There is NO Such Coord" << endl;
        return false;
    }

    Player *owner = road.getOwner();
    for (size_t i = 0; i < roads->size(); i++) // check if the road is already taken
    {
        if (roads->at(i).getCoord() == coord)
        {
            cout << "There is already road there" << endl;
            return false;
        }
    }

    for (size_t i = 0; i < settlements->size(); i++) // check if there is a settlement nearby
    {
        if (coords.isSettlementAdjacentRoad(coord, settlements->at(i).getCoord()))
        {
            Player *settlementOwner = settlements->at(i).getOwner();
            if (settlementOwner == owner)
            {
                return true;
            }
        }
    }

    // check if there is a road nearby
    for (size_t i = 0; i < roads->size(); i++)
    {
        Player *roadOwner = roads->at(i).getOwner();
        if (roadOwner == owner && coords.isRoadAdjacentRoad(coord, roads->at(i).getCoord()))
        {
            return true;
        }
    }

    cout << "Road can NOT be placed" << endl;
    return false;
}

/*
this function is used to place a road on the board and uses the function above checkRoadRules
to check if the road can be placed by the Rules that are adrressed in the function above
returns true if the road is placed successfully and false otherwise
*/
bool Board::placeRoad(string coord)
{
    if (GamePhase::DICEROLL == Catan::getInstance().getGamePhase())
    {
        cout << "You cannot Build you have not rolled the dice yet" << endl;
        return false;
    }
    Catan &c = Catan::getInstance();
    Player *player = c.getPlayerTurn();
    Road road(coord, *player);

    if (checkRoadRules(road)) // checkin if the road can be placed by going through the rules in the function above
    {
        if (c.getGamePhase() == SETUP1 || c.getGamePhase() == SETUP2 || c.getGamePhase() == FreeRoadBuilding) // check if the game phase is setup or FreeRoadBuilding
        {
            cout << player->getName() << " placed a Road on the coord " << coord << endl;
            roads->push_back(road); // add the road to the vector of roads
            return true;
        }
        else if (player->CanAfford("Road") && c.getGamePhase() == INPROCESS) // check if the player can afford the road and the game phase is in process
        {
            cout << player->getName() << " placed a Road on the coord " << coord << endl;
            player->deductResource("Road"); // deduct the resources from the player
            roads->push_back(road);         // add the road to the vector of roads
            return true;
        }
    }
    return false;
}
/*
this function is used to check if the city can be placed on the board by checking the following rules:
1. check if the coord exists
2. check if there is a settlement at the same coord as the city and owned by the same player
*/
bool Board::checkCityRules(City city)
{
    if (coords.ifVertexCoordExists(city.getCoord()) == false) // check if the coord exists
    {
        cout << "There is NO Such Coord" << endl;
        return false;
    }

    // if there is a settlement at the same coord as the city and owned by the same player then the city can be placed
    for (size_t i = 0; i < settlements->size(); i++)
    {
        if (settlements->at(i).getCoord() == city.getCoord() && settlements->at(i).getOwner() == city.getOwner())
        {
            cities->push_back(city);                      // add the city to the vector of cities
            settlements->erase(settlements->begin() + i); // remove the settlement from the vector of settlements
            return true;
        }
    }
    cout << "City cannot be placed" << endl;
    return false;
}
/*
this function is used to place a city on the board and uses the function above checkCityRules
returns true if the city is placed successfully and false otherwise
*/
bool Board::placeCity(string cord)
{
    if (GamePhase::DICEROLL == Catan::getInstance().getGamePhase()) // check if the game phase is in the DICEROLL phase
    {
        cout << "You cannot Build you have not rolled the dice yet" << endl; // if the game phase is in the DICEROLL phase then the city can not be placed
        return false;
    }
    Player player = *(Catan::getInstance().getPlayerTurn());
    City city(cord, player);

    // check if the player can afford the city and the city can be placed by checking the rules in the function above
    if (player.CanAfford("City") && checkCityRules(city))
    {
        cout << player.getName() << " placed a City on the coord " << cord << endl;
        player.deductResource("City"); // deduct the resources from the player
        cities->push_back(city);       // add the city to the vector of cities
        player.addPoints(1);           // add a point to the player
        return true;
    }
    else
    {
        cout << "City can not be placed" << endl;
        return false;
    }
}

void Board::printBoardStats()
{
    cout << "---------------------------------" << endl;
    cout << "Printing Board Stats......" << endl;
    // print all the roads
    for (size_t i = 0; i < roads->size(); i++)
    {
        cout << "Road at coord " << (*roads)[i].getCoord() << " owned by " << (*roads)[i].getOwner()->getName() << endl;
    }

    // print all the settlements
    for (size_t i = 0; i < settlements->size(); i++)
    {
        cout << "Settlements at coord " << (*settlements)[i].getCoord() << " owned by " << (*settlements)[i].getOwner()->getName() << endl;
    }

    // print all the cities
    for (size_t i = 0; i < cities->size(); i++)
    {
        cout << "City at coord " << (*cities)[i].getCoord() << " owned by " << (*cities)[i].getOwner()->getName() << endl;
    }
}