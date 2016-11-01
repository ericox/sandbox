// graph.h is an header interface for a graph
//
// Coursera: C++ for C programmers
// Assignment 2: Implement Dijkstra's algorithm
// Due Date: 8/22/2016 
// Author: Eric Cox
//
#include <vector>
#include <list>

using namespace std;

// Edge represents an edge in a graph
class Edge {
  public:
    Edge();
    Edge(int src, int dest, float cost);
    ~Edge();
    int Src() const;
    int Dest() const;
    float Weight() const;
  private:
    int src;
    int dest;
    float weight;
};

// Graph is an implementation of an undirected edge weighted graph
class Graph {
  public:
    // Constructs an empty graph 
    Graph(int nvert);
    // Constructs a random graph with nvert vertices and edge density
    Graph(int nvert, float edge_density);
    ~Graph();
    // Returns the number of vertices in the graph
    int V() const;
    // Returns the number of edges in the graph
    int E() const;
    // Add adds an edge to a graph.
    void AddEdge(Edge* e);
    // Tests whether there is an edge from vertex u to vertex v 
    bool Adjacent(int u, int v);
    // Neighbors returns a vector of edges that are reachable from u 
    void Neighbors(const int u, vector<Edge*>& neighbors) const;
  private:
    int vcnt;
    int ecnt;
    vector< list<Edge*> > adj;
};
