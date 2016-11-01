// graph.h is an header interface for a graph
//
// Coursera: C++ for C programmers
// Assignment 2: Implement Primms MST algorithm
// Due Date: 8/28/2016 
// Author: Eric Cox
//
#include <vector>
#include <list>

using namespace std;

// Node represents a node in a graph. 
// TODO: use a template here
class Node {
  public:
    Node();
    Node(int v);
    ~Node();
    void SetValue(int v) { value = v; }
    int GetValue() const { return value; }
  private:
    int value;
};

// Edge represents an edge in a graph
class Edge {
  public:
    Edge();
    Edge(Node* src, Node* dest, float cost);
    ~Edge();
    Node* Src() const { return src; };
    Node* Dest() const { return dest; };
    float Weight() const { return weight; };
  private:
    Node* src;
    Node* dest;
    float weight;
};

// Graph is an implementation of an undirected edge weighted graph
class Graph {
  public:
    // Constructs an empty graph 
    Graph(int nvert);
    // Constructs a graph from a file
    Graph(string filename);
    // Constructs a random graph with nvert vertices and edge density
    Graph(int nvert, float edge_density);
    ~Graph();
    // MakeGraph abstracts initialization for the single argument constructors
    void MakeGraph(int nvert);
    // Returns the number of vertices in the graph
    int V() const { return vcnt; };
    // Returns the number of edges in the graph
    int E() const { return ecnt; };
    // Add adds an edge to a graph.
    void AddEdge(Edge* e);
    // Tests whether there is an edge from vertex u to vertex v 
    bool Adjacent(const Node& u, const Node& v);
    // Neighbors returns a vector of edges that are reachable from u 
    void Neighbors(const Node& u, vector<Edge*>& neighbors) const;
  private:
    int vcnt;
    int ecnt;
    vector< list<Edge*> > adj;
};

// forward declaration for i/o operators
ostream& operator<<(ostream& out, Edge& e);
ostream& operator<<(ostream& out, Node& n);
bool operator==(const Node& a, const Node& b);
