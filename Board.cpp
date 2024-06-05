#include "Board.hpp"
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

Board::Board()
{
    coords = Coords();
    hexTiles = new vector<HexTile>();
    roads = new vector<Road>();
    settlements = new vector<Settlement>();
    cities = new vector<City>();
    initializeBoard();
}

Board::~Board()
{
    delete hexTiles;
    delete roads;
    delete settlements;
    delete cities;
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

bool Board::CheckSettlementsRules(Settlement settlement)
{
    string coord = settlement.coord;
    if (coords.ifVertexCoordExists(coord) == false)
    {
        cout << "There is NO Such Coord" << endl;
        return false;
    }

    Player owner = *(settlement.owner);

    for (size_t i = 0; i < settlements->size(); i++)
    {
        if (settlements->at(i).coord == settlement.coord)
        {
            cout << "SETTLEMENT ALREADY TAKEN !!" << endl;
            return false;
        }
    }

    // check if there is a settlement nearby
    for (size_t i = 0; i < settlements->size(); i++)
    {
        if (coords.isSettlementAdjacent((settlements->at(i).coord), coord))
        {
            cout << "Settlement Can NOT be placed there is another settlement nearby" << endl;
            return false;
        }
    }

    string edge1 = coord.substr(0, 2);
    string edge2 = coord.substr(1, 2);
    string edge3 = edge1.substr(0, 1) + edge2.substr(1, 1);

    if (owner.getfreeSettelments() == 0)
    {
        for (size_t i = 0; i < roads->size(); i++)
        {
            if (roads->at(i).coord == edge1 || roads->at(i).coord == edge2 || roads->at(i).coord == edge3)
            {
                if (roads->at(i).owner == owner)
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

    return false;
}

bool Board::CheckRoadsRules(Road road)
{
    string coord = road.coord;
    if (coords.ifEdgeCoordExists(coord) == false)
    {
        cout << "There is NO Such Coord" << endl;
        return false;
    }

    Player owner = road.owner;
    for (size_t i = 0; i < roads->size(); i++)
    {
        if (roads->at(i).coord == coord)
        {
            cout << "There is already road there" << endl;
            return false;
        }
    }

    // check if there is a settlement nearby
    for (size_t i = 0; i < settlements->size(); i++)
    {
        if (coords.isSettlementAdjacentRoad(coord, settlements->at(i).coord))
        {
            if (*(settlements->at(i).owner) == owner)
            {
                return true;
            }
        }
    }

    // check if there is a road nearby
    for (size_t i = 0; i < roads->size(); i++)
    {
        if (roads->at(i).owner == owner && coords.isRoadAdjacentRoad(coord, roads->at(i).coord))
        {
            return true;
        }
    }

    cout << "Road can NOT be placed" << endl;
    return false;
}

bool Board::CanPlaceCity(City city)
{
    if (coords.ifVertexCoordExists(city.coord) == false)
    {
        cout << "There is NO Such Coord" << endl;
        return false;
    }

    for (size_t i = 0; i < settlements->size(); i++)
    {
        if (settlements->at(i).coord == city.coord && settlements->at(i).owner == city.owner)
        {
            cities->push_back(city);
            settlements->erase(settlements->begin() + i);
            return true;
        }
    }
    cout << "City cannot be placed" << endl;
    return false;
}

void Board::placeRoad(string coord, Player &player)
{
    Road road(coord, player);

    if (CheckRoadsRules(road))
    {
        if (player.getfreeRoads() != 0)
        {
            cout << player.getName() << " placed a Road on the coord " << coord << endl;
            player.decrementfreeRoads();
            roads->push_back(road);
            return;
        }

        if (player.CanAfford("Road"))
        {
            cout << player.getName() << " placed a Road on the coord " << coord << endl;
            player.deductResource("Road");
            roads->push_back(road);
            return;
        }
    }
}

void Board::placeSettlement(string cord, Player &player)
{
    Settlement settlement(cord, player);
    if (CheckSettlementsRules(settlement))
    {
        if (player.getfreeSettelments() != 0)
        {
            cout << player.getName() << " placed a Settlement on the coord " << cord << endl;
            player.decrementfreeSettelments();
            settlements->push_back(settlement);
            return;
        }
        else if (player.CanAfford("Settlement"))
        {
            cout << player.getName() << " placed a Settlement on the coord " << cord << endl;
            player.deductResource("Settlement");
            return;
        }
    }
}

void Board::placeCity(string cord, Player &player)
{
    City city(cord, player);

    if (player.CanAfford("City") && CanPlaceCity(city))
    {
        cout << player.getName() << " placed a City on the coord " << cord << endl;
        player.deductResource("City");
        return;
    }
    else
    {
        cout << "City can not be placed" << endl;
    }
}

string getResourceName(ResourceType resource)
{
    switch (resource)
    {
    case DESERT:
        return "Desert";
    case WOOD:
        return "Wood";
    case BRICK:
        return "Brick";
    case WOOL:
        return "WOOL";
    case WHEAT:
        return "Wheat";
    case IRON:
        return "IRON";
    default:
        return "None";
    }
}

void Board::printBoardStats()
{
    // print all the roads
    for (size_t i = 0; i < roads->size(); i++)
    {
        cout << "Road at coord " << (*roads)[i].coord << " owned by " << (*roads)[i].owner.getName() << endl;
    }

    // print all the settlements
    for (size_t i = 0; i < settlements->size(); i++)
    {
        cout << "Settlement at coord " << (*settlements)[i].coord << " owned by " << (*settlements)[i].owner->getName() << endl;
    }

    // print all the cities
    for (size_t i = 0; i < cities->size(); i++)
    {
        cout << "City at coord " << (*cities)[i].coord << " owned by " << (*cities)[i].owner->getName() << endl;
    }
}
