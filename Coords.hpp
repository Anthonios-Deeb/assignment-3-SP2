// 3993
// anthoniosdb@gmail.com
#ifndef COORDS_HPP
#define COORDS_HPP
#include <string>
#include <vector>

using namespace std;

class Coords
{
public:
  Coords();
  vector<string> getVerticesCords();     // returns the vertices cords
  vector<string> getEdgesCords();        // returns the edges cords
  bool ifEdgeCoordExists(string cord);   // checks if the edge cord exists
  bool ifVertexCoordExists(string cord); // checks if the vertex cord exists
  bool isSettlementAdjacent(string cord1, string cord2);
  bool isSettlementAdjacentRoad(string cord1, string cord2); // given a road and a settlement I want to check if any 2 charecters from the road match with any 2 charecters from the settlement
  bool isRoadAdjacentRoad(string cord1, string cord2);       // given 2 cords I want to check if I can make any 3 chars combination that matches one of the vertices cords

private:
  void initilaizeVerticesCoords();
  void initilaizeEdgesCoords();

  vector<string> verticesCords;
  vector<string> edgesCords;
};
#endif // COORDS_HPP