// 3993
// anthoniosdb@gmail.com
#include "Coords.hpp"
#include <iostream>

// initialize the list of vertices coords
void Coords ::initilaizeVerticesCoords()
{
  verticesCords.push_back("Aab");
  verticesCords.push_back("Bbc");
  verticesCords.push_back("Ccd");
  //
  verticesCords.push_back("Ara");
  verticesCords.push_back("ABb");
  verticesCords.push_back("BcC");
  verticesCords.push_back("Cde");
  //
  verticesCords.push_back("DrA");
  verticesCords.push_back("AEB");
  verticesCords.push_back("BCF");
  verticesCords.push_back("CeG");
  //
  verticesCords.push_back("Dqr");
  verticesCords.push_back("DAE");
  verticesCords.push_back("EBF");
  verticesCords.push_back("CFG");
  verticesCords.push_back("Gef");
  //
  verticesCords.push_back("HqD");
  verticesCords.push_back("DEI");
  verticesCords.push_back("EFJ");
  verticesCords.push_back("FGK");
  verticesCords.push_back("GfL");
  //
  verticesCords.push_back("Hpq");
  verticesCords.push_back("HDI");
  verticesCords.push_back("IEJ");
  verticesCords.push_back("JFK");
  verticesCords.push_back("GKL");
  verticesCords.push_back("LfG");
  //
  verticesCords.push_back("Hop");
  verticesCords.push_back("HMI");
  verticesCords.push_back("IJN");
  verticesCords.push_back("JKO");
  verticesCords.push_back("KLP");
  verticesCords.push_back("Lgh");
  //
  verticesCords.push_back("MoH");
  verticesCords.push_back("MIN");
  verticesCords.push_back("NJO");
  verticesCords.push_back("KOP");
  verticesCords.push_back("LPh");
  //
  verticesCords.push_back("Mno");
  verticesCords.push_back("MQN");
  verticesCords.push_back("NRO");
  verticesCords.push_back("OPS");
  verticesCords.push_back("Phi");
  //
  verticesCords.push_back("QnM");
  verticesCords.push_back("QNR");
  verticesCords.push_back("ROS");
  verticesCords.push_back("PiS");
  //
  verticesCords.push_back("Qmn");
  verticesCords.push_back("RlQ");
  verticesCords.push_back("SkR");
  verticesCords.push_back("Sij");
  //
  verticesCords.push_back("Qlm");
  verticesCords.push_back("Rkl");
  verticesCords.push_back("Sjk");
}

// initialize the list of edges coords
void Coords ::initilaizeEdgesCoords()
{
  edgesCords.push_back("Aa");
  edgesCords.push_back("Ab");
  edgesCords.push_back("Bb");
  edgesCords.push_back("Bc");
  edgesCords.push_back("Cc");
  edgesCords.push_back("Cd");

  edgesCords.push_back("Ar");
  edgesCords.push_back("AB");
  edgesCords.push_back("BC");
  edgesCords.push_back("Ce");

  edgesCords.push_back("Dr");
  edgesCords.push_back("AD");
  edgesCords.push_back("AE");
  edgesCords.push_back("EB");
  edgesCords.push_back("BF");
  edgesCords.push_back("FC");
  edgesCords.push_back("CG");
  edgesCords.push_back("Ge");

  edgesCords.push_back("Dq");
  edgesCords.push_back("DE");
  edgesCords.push_back("EF");
  edgesCords.push_back("FG");
  edgesCords.push_back("Gf");

  edgesCords.push_back("Hq");
  edgesCords.push_back("DH");
  edgesCords.push_back("DI");
  edgesCords.push_back("IE");
  edgesCords.push_back("EJ");
  edgesCords.push_back("FJ");
  edgesCords.push_back("FK");
  edgesCords.push_back("GK");
  edgesCords.push_back("LG");
  edgesCords.push_back("Lf");

  edgesCords.push_back("Hp");
  edgesCords.push_back("HI");
  edgesCords.push_back("IJ");
  edgesCords.push_back("JK");
  edgesCords.push_back("KL");
  edgesCords.push_back("Lg");

  edgesCords.push_back("Ho");
  edgesCords.push_back("HM");
  edgesCords.push_back("MI");
  edgesCords.push_back("IN");
  edgesCords.push_back("NJ");
  edgesCords.push_back("JO");
  edgesCords.push_back("KO");
  edgesCords.push_back("KP");
  edgesCords.push_back("PL");
  edgesCords.push_back("Lh");

  edgesCords.push_back("Mo");
  edgesCords.push_back("MN");
  edgesCords.push_back("NO");
  edgesCords.push_back("OP");
  edgesCords.push_back("Ph");

  edgesCords.push_back("Mn");
  edgesCords.push_back("MQ");
  edgesCords.push_back("QN");
  edgesCords.push_back("NR");
  edgesCords.push_back("RO");
  edgesCords.push_back("OS");
  edgesCords.push_back("PS");
  edgesCords.push_back("Pi");

  edgesCords.push_back("Qn");
  edgesCords.push_back("QR");
  edgesCords.push_back("RS");
  edgesCords.push_back("Si");

  edgesCords.push_back("Qm");
  edgesCords.push_back("Ql");
  edgesCords.push_back("Rl");
  edgesCords.push_back("Rk");
  edgesCords.push_back("Sk");
  edgesCords.push_back("Sj");
}

Coords::Coords()
{
  initilaizeVerticesCoords();
  initilaizeEdgesCoords();
}

vector<string> Coords::getVerticesCords()
{
  return verticesCords;
}

vector<string> Coords::getEdgesCords()
{
  return edgesCords;
}

// both of the strings are 3 characters long I want to check if any 2 charecters from cord1 match with any 2 charecters from cord2
bool Coords::isSettlementAdjacent(string cord1, string cord2)
{
  int count = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (cord1[i] == cord2[j])
      {
        count++;
      }
    }
  }
  return count == 2;
}

// given a road and a settlement I want to check if any 2 charecters from the road match with any 2 charecters from the settlement
bool Coords::isSettlementAdjacentRoad(string roadCoord, string SettlementCoord)
{
  int count = 0;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (roadCoord[i] == SettlementCoord[j])
      {
        count++;
      }
    }
  }
  return count >= 2;
}

// given 2 cords I want to check if I can make any 3 chars combination that matches one of the vertices cords
bool Coords::isRoadAdjacentRoad(string cord1, string cord2)
{
  // check if there is no common char between the two cords
  if (cord1[0] != cord2[0] && cord1[0] != cord2[1] && cord1[1] != cord2[0] && cord1[1] != cord2[1])
  {
    return false;
  }

  // get the three chars
  string c1 = cord1.substr(0, 1);
  string c2 = cord1.substr(1, 1);
  string c3;
  if (c1 == cord2.substr(0, 1) || c2 == cord1.substr(0, 1))
  {
    c3 = cord2.substr(1, 1);
  }
  else
  {
    c3 = cord2.substr(0, 1);
  }

  // check if the combination exists in the list of vertices cords
  string atempt1 = c1 + c2 + c3;
  string atempt2 = c1 + c3 + c2;
  string atempt3 = c2 + c1 + c3;
  string atempt4 = c2 + c3 + c1;
  string atempt5 = c3 + c1 + c2;
  string atempt6 = c3 + c2 + c1;

  // check if the combination exists in the list of vertices cords
  for (size_t i = 0; i < verticesCords.size(); i++)
  {
    if (verticesCords[i] == atempt1 || verticesCords[i] == atempt2 || verticesCords[i] == atempt3 || verticesCords[i] == atempt4 || verticesCords[i] == atempt5 || verticesCords[i] == atempt6)
    {
      return true;
    }
  }
  return false;
}

// check if the edge cord exists in the list of edge cords
bool Coords::ifEdgeCoordExists(string cord)
{
  for (size_t i = 0; i < edgesCords.size(); i++)
  {
    if (edgesCords[i] == cord)
    {
      return true;
    }
  }
  return false;
}

// check if the vertex cord exists in the list of vertex cords
bool Coords::ifVertexCoordExists(string cord)
{
  for (size_t i = 0; i < verticesCords.size(); i++)
  {
    if (verticesCords[i] == cord)
    {
      return true;
    }
  }
  return false;
}