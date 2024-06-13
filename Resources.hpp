// 3993
// anthoniosdb@gmail.com
#ifndef RESOURCES_HPP
#define RESOURCES_HPP
#include <string>
using namespace std;

enum ResourceType
{
  WOOD,
  BRICK,
  WHEAT,
  WOOL,
  IRON,
  DESERT,
  NONE
};
string getResourceName(ResourceType resource);
enum ResourceType getResourceType(string resource);

#endif // RESOURCES_HPP