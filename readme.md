# Catan 

![Board](https://github.com/Anthonios-Deeb/assignment-3-SP2/blob/main/A.webp)

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

# Catan Class README

## Overview

The `Catan` class represents a simulation of the popular board game "Settlers of Catan". It manages game phases, players, a game board, and cards used in the game. This README provides an overview of its functionality and usage.

## Contents

1. **Files Included:**
   - `Catan.hpp`: Header file for the `Catan` class.
   - `Catan.cpp`: Implementation file for the `Catan` class.
   - Other headers: `Board.hpp`, `Player.hpp`, `Card.hpp`.
   
2. **Dependencies:**
   - Standard Library: `<thread>`, `<atomic>`, `<queue>`.
   - Custom Components: `Board`, `Player`, `Card`.

## Class Members

### Public Methods

- **`void addPlayers(Player *p1, Player *p2, Player *p3, Player *p4 = nullptr)`**
  - Adds players to the game.
  - `p1` to `p4` (optional): Pointers to Player objects representing game participants.

- **`vector<Player *> *getPlayers()`**
  - Returns a pointer to the vector of all players currently in the game.

- **`Board *getBoard()`**
  - Returns a pointer to the Board object representing the game board.

- **`vector<Card *> *getCards()`**
  - Returns a pointer to the vector of all cards used in the game.

- **`GamePhase getGamePhase()`**
  - Returns the current phase of the game (e.g., SETUP1, SETUP2, INPROCESS, etc.).

- **`Player *getPlayerTurn()`**
  - Returns a pointer to the player whose turn it currently is.

- **`void chooseStartingPlayer()`**
  - Initiates the process to choose the starting player for the game.

- **`Player *endTurn()`**
  - Moves the game to the next player's turn.
  - Returns a pointer to the player whose turn it now is.

- **`void setGamePhase(GamePhase phase)`**
  - Sets the current phase of the game to the specified phase.

- **`void resetGame()`**
  - Resets the game to its initial state.

### Private Methods

- **`void initializeCards()`**
  - Initializes the cards used in the game.

- **`void checkWinner()`**
  - Checks if there is a winner based on game conditions.

- **`void startGame()`**
  - Starts the game process.

## Usage

To use the `Catan` class in your application:

1. Include `"Catan.hpp"` in your source files.
2. Create an instance of `Catan` using `Catan &game = Catan::getInstance();`.
3. Add players using `game.addPlayers(player1, player2, player3, player4);`.
4. Access game components and control flow using methods such as `getPlayers`, `getBoard`, `getGamePhase`, `getPlayerTurn`, etc.
5. Use methods like `chooseStartingPlayer`, `endTurn`, `setGamePhase`, and `resetGame` to manage game progress and state.

## Notes

- Ensure that the game progresses through phases (`SETUP1`, `SETUP2`, `INPROCESS`, etc.) in accordance with game rules.
- Implement game-specific logic in methods like `initializeCards`, `checkWinner`, and `startGame` as per the rules of "Settlers of Catan".
- Consider thread safety for methods involving game state updates (`setGamePhase`, `endTurn`) due to concurrent access from multiple players.

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

# Player Class README

## Overview

The `Player` class represents a participant in the game (possibly "Settlers of Catan") with attributes such as name, points, resources, and cards. This class manages player actions such as rolling dice, buying and using cards, trading resources and cards with other players, and handling game-specific rules like the largest army.

## Contents

1. **Files Included:**
   - `Player.hpp`: Header file for the `Player` class.
   - `Player.cpp`: Implementation file for the `Player` class.
   - Other headers: `Resources.hpp`, `CardType.hpp`.

2. **Dependencies:**
   - Standard Library: `<string>`, `<vector>`, `<map>`, `<iostream>`.
   - External Libraries: `<random>`, `<chrono>` (for random number generation).

## Class Members

### Public Methods

- **`Player(string name)`**
  - Constructor to initialize a player with a given name.

- **`~Player()`**
  - Destructor to clean up player resources and cards.

- **`bool operator==(const Player &p)`**
  - Overloaded equality operator to compare players based on their attributes.

- **`string getName()`**
  - Returns the name of the player.

- **`int getPoints()`**
  - Returns the current points of the player.

- **`map<ResourceType, int> *getResources()`**
  - Returns a pointer to the map of resources (e.g., wood, brick, etc.) held by the player.

- **`int RollDice()`**
  - Simulates rolling dice and distributes resources to the player based on the roll.

- **`void buyCard()`**
  - Allows the player to purchase a card.

- **`void useCard(CardType type)`**
  - Uses a card of the specified type from the player's hand.

- **Trade Methods (Public):**
  - Methods to facilitate trading resources and cards with other players:
    - `tradeResourceToResource`
    - `tradeResourceToCard`
    - `tradeCardToCard`
    - `tradeCardToResource`

### Private Methods

- **`Card *drawCard()`**
  - Draws a card from the deck.

- **`void isSevenRolledTax(int diceRoll)`**
  - Checks if a 7 is rolled and applies the associated game rules (e.g., resource tax).

- **`void checkLargestArmy()`**
  - Checks if the player has the largest army based on game rules.

- **`void addResource(ResourceType type, bool isCity = false)`**
  - Adds resources to the player after rolling the dice.

- **`void addPoints(int p)`**
  - Adds points to the player's score.

- **`void deductResource(string type)`**
  - Deducts resources from the player after building a road, settlement, or city.

- **`void setResource(ResourceType type, int amount)`**
  - Sets a specific amount of resources for the player.

- **`bool CanAfford(string type)`**
  - Checks if the player can afford to build a road, settlement, or city.

## Usage

To use the `Player` class in your application:

1. Include `"Player.hpp"` in your source files.
2. Create instances of `Player` using `Player player1("Player1");`, `Player player2("Player2");`, etc.
3. Use public methods like `RollDice`, `buyCard`, `useCard`, and trade methods to manage player actions and interactions within the game.
4. Access player attributes such as name, points, and resources using getter methods like `getName`, `getPoints`, and `getResources`.

## Notes

- Ensure that game-specific rules and conditions (like largest army) are implemented and validated in corresponding methods (`checkLargestArmy`, `isSevenRolledTax`, etc.).
- Implement error handling and validation where appropriate, especially for resource management and player interactions.
- Customize trade methods and game actions as per your game's rules and requirements, ensuring consistency and fairness in gameplay.
