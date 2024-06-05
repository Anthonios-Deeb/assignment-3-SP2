#ifndef COORDS_HPP
#define COORDS_HPP
#include <string>
#include <vector>

using namespace std;

class Coords
{
public:
  Coords();
  vector<string> getVerticesCords();
  vector<string> getEdgesCords();
  bool ifEdgeCoordExists(string cord);
  bool ifVertexCoordExists(string cord);
  bool isSettlementAdjacent(string cord1, string cord2);
  bool isSettlementAdjacentRoad(string cord1, string cord2);
  bool isRoadAdjacentRoad(string cord1, string cord2);

private:
  void initilaizeVerticesCords();
  void initilaizeEdgesCords();

  vector<string> verticesCords;
  vector<string> edgesCords;
};
#endif // COORDS_HPP