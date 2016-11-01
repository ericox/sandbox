// graph.cpp is an implementation of the interface for a graph
//
// Coursera: C++ for C programmers
// Assignment 3: Implement Primms MST algorithm
// Due Date: 8/28/2016 
// Author: Eric Cox
//
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include "graph.h"

using namespace std;

//
// Implementation of Node
//
Node::Node(): value(0) {}
Node::Node(int v): value(v) {}
Node::~Node() {}

ostream& operator<<(ostream& out, Node& n)
{
  out << n.GetValue(); 
  return out;
}

bool operator==(const Node& a, const Node& b)
{
  return a.GetValue() == a.GetValue();
}

//
// Implementation of Edge
// 
Edge::Edge(): src(0), dest(0), weight(0.0) {};
Edge::Edge(Node* v, Node* w, float cost=0.0): src(v), dest(w), weight(cost) {};
Edge::~Edge() {};

ostream& operator<<(ostream& out, Edge& e)
{
  out << "(" << *(e.Src()) << ", " << *(e.Dest()) << ", "
      << e.Weight() << ")";
  return out;
}

//
// Implementation of Graph 
//
// Constructor with a single argument that initializes the number
// of vertices in the graph.
Graph::Graph(int nvert) 
  : vcnt(nvert), ecnt(0) 
{
  // Create space for nverts in the graph
  MakeGraph(nvert);
}


// This constructor marches through the file and builds a graph.  
Graph::Graph(string filename)
{
  ifstream edge_file(filename);
  istream_iterator<string> start(edge_file), end;
  vector<string> edges(start, end); 
  int n = 0;
  float cost = 0.0;
  Node* node_src = nullptr;
  Node* node_dest = nullptr;
  Edge* e = nullptr;
  for(auto item: edges)
  {
    if (n == 0) {
      // Create space for nverts in the graph
      int nvert = stoi(item);
      MakeGraph(nvert);
      vcnt = nvert;
    } else {
      switch (n%3) {
        case 1: { 
          node_src = new Node(stoi(item));
          break;
        }
        case 2: { 
          node_dest = new Node(stoi(item));
          break;
        }
        case 0: {
          cost = stof(item);
          e = new Edge(node_src, node_dest, cost);
          AddEdge(e);
          break;
        }
      }
    }
    ++n;
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
        Node* u = new Node(i);
        Node* v = new Node(j);
        Edge* e = new Edge(u, v, randwt(gen));
        AddEdge(e);
      }
}

Graph::~Graph()
{
  for (vector< list<Edge*> >::iterator row = adj.begin(); row != adj.end(); ++row) {
    row->clear();
  }
  adj.clear();
}

void Graph::MakeGraph(int nvert)
{
  adj = vector< list<Edge*> >(0);
  for (int i = 0; i < nvert; ++i) {
    list<Edge*> lst = list<Edge*>();
    adj.push_back(lst);
  }
}

void Graph::AddEdge(Edge* e)
{
  Node* v = e->Src();
  Node* w = e->Dest();
  adj[v->GetValue()].push_back(e);
  adj[w->GetValue()].push_back(e);
  ecnt++;
  return;
}

bool Graph::Adjacent(const Node& u, const Node& v)
{
  // Gets all edges of u and tests if v is a node in either the
  // Src or Dest.
  list<Edge*> row = adj[u.GetValue()]; 
  for (list<Edge*>::iterator it = row.begin(); it != row.end(); ++it)
    if ((*(*it)->Src()) == v || (*(*it)->Dest()) == v)
      return true;
  return false;
}

void Graph::Neighbors(const Node& u, vector<Edge*>& n) const
{
  list<Edge*> e = adj[u.GetValue()];
  for (auto it = e.cbegin(); it != e.cend(); ++it)
    n.push_back(*it);
  return; 
}
