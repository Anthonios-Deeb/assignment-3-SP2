## Catan 

### Overview
In this project we have multiple classes :
-`Catan`: This class represents the game itself.
-`Board`: This class represents the Board in the game.
-`Settlement`: This class

### Features
- `Load Graph`: Load a graph into the `Graph` object.
- `Print Graph`: Print the adjacency list representation of the loaded graph.
- `Get Adjacency Matrix`: Retrieve the adjacency matrix of the loaded graph.

### Usage
1. `Constructor`: Default constructor to initialize the graph.
2. `Destructor`: The destructor is defaulted, handling memory deallocation.
3. `Load Graph`: Use the loadGraph method to load a graph represented by a vector of vectors of integers.
4. `printGraph()`:  Call the printGraph method to print the adjacency list representation of the loaded graph.
5. `getNumVertices()`: Method to get the number of vertices in the graph.
7. `getAdjacencyMatrix()`: Use the getAdjMatrix method to retrieve the adjacency matrix of the loaded graph.

### Usage
To use this class, include the `Graph.hpp` header file in your C++ project. Instantiate an object of the `Graph` class and use its methods to perform operations on the graph.

Example:
```cpp
#include "Graph.hpp"
#include <iostream>

int main() {
  Graph myGraph;
  vector<vector<int>> adjacencyList = {
    {0, 1, 1, 0},
    {1, 0, 0, 1},
    {1, 0, 0, 1},
    {0, 1, 1, 0}};
myGraph.loadGraph(adjacencyList);
myGraph.printGraph();
vector<vector<int>> adjacencyMatrix = myGraph.getAdjMatrix();
return 0;
}
```

## Algorithms Class

The following algorithms are implemented:

- `isConnected(Graph& g)`: Determines whether the graph is connected or not. Returns a boolean value indicating connectivity.
- `shortestPath(Graph& g, int start, int end)`: Computes the shortest path between two nodes in the graph. Returns the shortest path as a string if one exists, otherwise returns -1.
- `isContainsCycle(Graph& g)`: Checks if the graph contains a cycles. Returns a string that contains the path of the cycle if found, otherwise returns an -1.
- `isBipartite(Graph& g)`: Determines whether the graph is bipartite or not. Returns a string that contains two sets if bipartite, otherwise returns -1.
- `negativeCycle(Graph& g)`: Checks if the graph contains a negative cycle. Returns a string of the negative cycle if found, otherwise returns -1.

### Usage

To use the `Algorithms` class, include the `Algorithms.hpp` header file in your C++ source code. Then, call the desired static methods by passing a reference to a Graph object as an argument.

```cpp
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>

using namespace ariel;

int main() {
    // Create a Graph object and populate it with data

    // Example 1: Check if the graph is connected
    Graph graph1;
    // Load graph data into graph1
    int connected = Algorithms::isConnected(graph1);
    if (connected) {
        std::cout << "The graph is connected." << std::endl;
    } else {
        std::cout << "The graph is not connected." << std::endl;
    }

    // Example 2: Find the shortest path between two vertices
    Graph graph2;
    // Load graph data into graph2
    std::string path = Algorithms::shortestPath(graph2, startVertex, endVertex);
    std::cout << "Shortest path: " << path << std::endl;

    // Additional examples for other algorithms...
    
    return 0;
}
