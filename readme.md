# Catan 

### Overview
In this project we have multiple classes :
-`Catan`: This class represents the game itself.
-`Board`: This class represents the board in the game.
-`HexTile`: This class represnets a hextile that is used to make the Board.
-`Coords`: This class contains all the coorinations.
-`Resources`:This class contains the enum for all the resources.
-`Card`: This files contains different classes each class represnt a different type of card.
-`CardType`: This class contains the enum for the types of cards.
-`Settlement`: This class represents a settelemnt.
-`Road`: This class represents a road.
-`City`: This class represents a city.
-`Player`: This class represents a player

I'm only going to address Catan, Board, Player

## Board Class

## Overview

The `Board` class represents a Catan game board that includes hexagonal tiles, roads, settlements, and cities. It provides functionalities to place and manage these components on the board.

## Contents

1. **Files Included:**
   - `Board.hpp`: Header file for the `Board` class.
   - `Board.cpp`: Implementation file for the `Board` class.
   - Other headers: `HexTile.hpp`, `Road.hpp`, `Settlement.hpp`, `City.hpp`, `Coords.hpp`.

2. **Dependencies:**
   - Standard Library: `<string>`, `<vector>`.
   - Custom Components: `HexTile`, `Road`, `Settlement`, `City`, `Coords`.

## Class Members

### Public Methods

- **`bool placeRoad(string cord)`**
  - Attempts to place a road on the board at the specified coordinates.
  - Returns `true` if the road is placed successfully.

- **`bool placeSettlement(string cord)`**
  - Attempts to place a settlement on the board at the specified coordinates.
  - Returns `true` if the settlement is placed successfully.

- **`bool placeCity(string cord)`**
  - Attempts to place a city on the board at the specified coordinates.
  - Returns `true` if the city is placed successfully.

- **`void printBoardStats()`**
  - Prints information about the settlements, cities, and roads currently on the board.

- **`vector<Settlement> *getSettlements()`**
  - Returns a pointer to the vector of settlements currently on the board.

- **`vector<Road> *getRoads()`**
  - Returns a pointer to the vector of roads currently on the board.

- **`vector<City> *getCities()`**
  - Returns a pointer to the vector of cities currently on the board.

- **`vector<HexTile> *getHexTiles()`**
  - Returns a pointer to the vector of hexagonal tiles representing the board.

### Private Methods

- **`void initializeBoard()`**
  - Initializes the board with hexagonal tiles and sets up initial configurations.

- **`bool checkCityRules(City city)`**
  - Checks if placing a city at a given location complies with game rules.

- **`bool checkSettlementRules(Settlement settlement)`**
  - Checks if placing a settlement at a given location complies with game rules.

- **`bool checkRoadRules(Road road)`**
  - Checks if placing a road at a given location complies with game rules.

## Usage

To use the `Board` class in your application:

1. Include `"Board.hpp"` in your source files.
2. Create an instance of `Board` using `Board board;`.
3. Use public methods like `placeRoad`, `placeSettlement`, and `placeCity` to interact with the board.
4. Access board statistics or specific components using getter methods like `getSettlements`, `getRoads`, etc.

## Notes

- Ensure that coordinates passed to `placeRoad`, `placeSettlement`, and `placeCity` are valid and within the bounds of the board.
- Implement additional game rules and validations in the respective check methods (`checkCityRules`, `checkSettlementRules`, `checkRoadRules`) as per your game's requirements.
