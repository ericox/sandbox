// graph.cpp is an implementation of the interface for a graph
//
// Coursera: C++ for C programmers
// Assignment 2: Implement Dijkstra's algorithm
// Due Date: 8/22/2016 
// Author: Eric Cox
//
#include <iostream>
#include <random>
#include <chrono>
#include "graph.h"

using namespace std;

//
// Implementation of Edge
// 
Edge::Edge(): src(0), dest(0), weight(0.0) {};

Edge::Edge(int v, int w, float cost=0.0): src(v), dest(w), weight(cost) {};

Edge::~Edge() {};

int Edge::Src()
{
  return src;
}

int Edge::Dest()
{
  return dest;
}

float Edge::Weight()
{
  return weight;
}

ostream& operator<<(ostream& out, Edge& e)
{
  out << "(" << e.Src() << ", " << e.Dest() << ", "
      << e.Weight() << ")";
  return out;
}

//
// Implementation of Graph 
//
// Default constructor with a single argument that initializes the number
// of vertices in the graph.
Graph::Graph(int nvert) 
  : vcnt(nvert), ecnt(0) 
{
  adj = vector< list<Edge*> >(0);
  for (int i = 0; i < nvert; ++i) {
    list<Edge*> lst = list<Edge*>();
    adj.push_back(lst);
  }
}

Graph::Graph(int nvert, float edge_density)
  : Graph(nvert) 
{
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine gen(seed);
  uniform_real_distribution<float> rand(0.0, 1.0);
  uniform_real_distribution<float> randwt(0.0, 100.0);
  for (int i = 0; i < nvert; ++i)
    for (int j = i; j < nvert; ++j)
      if (i == j) {
        continue;
      } else if (rand(gen) < edge_density) {
        Edge* e = new Edge(i, j, randwt(gen));
        AddEdge(e);
      }
}

Graph::~Graph() {
  for (vector< list<Edge*> >::iterator row = adj.begin(); row != adj.end(); ++row) {
    row->clear();
  }
  adj.clear();
}

int Graph::V()
{
  return vcnt;
}

int Graph::E() 
{
  return ecnt;
}

void Graph::AddEdge(Edge* e)
{
  int v = e->Src();
  int w = e->Dest();
  adj[v].push_back(e);
  adj[w].push_back(e);
  ecnt++;
  return;
}

bool Graph::Adjacent(int u, int v)
{
  list<Edge*> row = adj[u]; 
  for (list<Edge*>::iterator it = row.begin(); it != row.end(); ++it)
    if ((*it)->Src() == v || (*it)->Dest() == v)
      return true;
  return false;
}

void Graph::Neighbors(const int u, vector<Edge*>& n) 
{
  list<Edge*> e = adj[u];
  for (auto it = e.cbegin(); it != e.cend(); ++it)
    n.push_back(*it);
  return; 
}

int main()
{
  Edge e(1, 3);
  cout << "test: " << e << endl;

  Graph g(10, 0.1);
  vector<Edge*> neighbors(0);
  cout << "Graph Len: " << g.E() << endl;
  cout << "Graph V Len: " << g.V() << endl;
  g.Neighbors(1, neighbors);
  for (vector<Edge*>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
    cout << "Graph neighbors: " << (*it)->Src() << ", " << (*it)->Dest() << endl;

  neighbors.clear();
  g.Neighbors(5, neighbors);
  for (vector<Edge*>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
    cout << "Graph neighbors: " << (*it)->Src() << ", " << (*it)->Dest() << endl;

  cout << g.Adjacent(1, 5) << endl;
}
