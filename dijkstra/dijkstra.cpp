// dijkstra.cpp is an implementation of the dijkstra's shortest path algorithm 
//
// Coursera: C++ for C programmers
// Assignment 2: Implement Dijkstra's algorithm
// Due Date: 8/22/2016 
// Author: Eric Cox
//
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <limits>
#include "dijkstra.h"
#include "graph.h"

using namespace std;

// heapArg wraps the node id and it's priority. This is used to implement a min-heap
class heapArg {
  private:
    float priority;
    int value;
  public:
    heapArg(const int& k, const float& v) : value(k), priority(v){ }
    float getPriority() const { return priority; }
    void setPriority(float v) { priority = v; } 
    int getValue() const { return value; }
    void setValue (int k) { value = k; } 
};

// comp is a comparison class for the min-heap of heapArg objects.
class comp {
  public:
    comp() { }
    bool operator() (const heapArg& lhs, const heapArg& rhs) {
      return (lhs.getPriority() < rhs.getPriority()); 
    }
};

// Implementation
ShortestPath::ShortestPath(const Graph& g) : graph(g)
{
  priority_queue<heapArg, vector<heapArg>, comp>* queue = new priority_queue<heapArg, vector<heapArg>, comp>;
  vector<float> dist = vector<float>(graph.V());
  vector<Edge*> edgeTo = vector<Edge*>(graph.V());
}

ShortestPath::~ShortestPath() { }; 

void ShortestPath::Path(int src, int dest) {
  float inf = numeric_limits<float>::infinity();
  float src_val = 0.0;

  set<int> open; // Set of unvisited nodes  
  set<int> closed;  // Set of visited nodes 
  dist[src] = src_val;
  edgeTo.clear();
  if (!queue->empty())
    while (!queue->empty())
      queue->pop();
    
  // Algorithm
  for (int i = 0; i < graph.V(); ++i) {
    if (i != src) {
      dist[i] = inf;
      edgeTo[i] = nullptr;
    }
    heapArg item(i, inf);
    queue->push(&item);
  }

  open.insert(src);
  while (!queue.empty())
    // TODO: Fillin algorithm...
}

ShortestPath::PathSize(int src, int dest) {
  return edgeTo.size();
}
