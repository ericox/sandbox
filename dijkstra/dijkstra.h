// dijkstra.h is an header interface for the dijkstra's shortest path algorithm 
//
// Coursera: C++ for C programmers
// Assignment 2: Implement Dijkstra's algorithm
// Due Date: 8/22/2016 
// Author: Eric Cox
//
#include <vector>
#include "graph.h"

using namespace std;

// ShortestPath creates a new instance of the Dijkstra's shortest path
// algoithm and solves it using the min-heap variation.
class ShortestPath {
  public:
    ShortestPath(const Graph& g);
    ~ShortestPath();

    // Path runs the shortest path algorithm given the source and destinations.
    void Path(int src, int dest);
    
    // PathSize returns the total cost of the path found by invoking Path. 
    float PathSize(int src, int dest);

  private:
    // Stores the graph to run the algorithm on
    const Graph& graph;
    // A min-heap for access to the next node with least distance
    priority_queue<int>* queue;
    // Tracks the tentative distances during the search
    vector<float> dist;
    // Tracks the optimal path
    vector<Edge*> edgeTo;
};
