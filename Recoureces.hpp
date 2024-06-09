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

static string getResourceName(ResourceType resource)
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
        return "Wool";
    case WHEAT:
        return "Wheat";
    case IRON:
        return "Iron";
    default:
        return "None";
    }
}

static enum ResourceType getResourceType(string resource)
{
    // convert string to lowercase
    for (int i = 0; i < resource.length(); i++)
    {
        resource[i] = tolower(resource[i]);
    }

    if (resource == "desert")
    {
        return DESERT;
    }
    else if (resource == "wood")
    {
        return WOOD;
    }
    else if (resource == "brick")
    {
        return BRICK;
    }
    else if (resource == "wool")
    {
        return WOOL;
    }
    else if (resource == "wheat")
    {
        return WHEAT;
    }
    else if (resource == "iron")
    {
        return IRON;
    }
    else
    {
        return NONE;
    }
}


#endif // RESOURCES_HPP