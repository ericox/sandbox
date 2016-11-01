#include<iostream>
#include<limits>
#include "prim_mst.h"

using namespace std;


PrimJarnikMST::PrimJarnikMST(const Graph* g, const Node& start_node) 
  : g(g)
{

  const int nvert = g->V(); 
  dist = vector<float>(nvert); 
  edges = vector<Node*>(nvert); 
  mst = vector<Edge*>(0); 
  edge_pqueue heap;

  // init dist and edge vectors
  set_dist_edges(nvert);

  // Set the distance of the start_node to itself. This is the base-case
  // and the distance of a node to itself is zero. Also we init the heap
  // with the starting node's neighbors.
  dist[start_node.GetValue()] = 0.0;
  vector<Edge*> neighbors; 
  g->Neighbors(start_node, neighbors);
  for (auto edge: neighbors)
    heap.push(edge);

  // Main loop. The spanning tree has nvert-1 edges.
  while (mst.size() < nvert-1) 
  {
    // Pick node v, in heap w/ the shortest edge to the group of nodes in the
    // spanning tree. Add v to the mst.
    Edge* e = heap.top();
    heap.pop();
    mst.push_back(e);

    // Get the neighbors of the shortest edge to the group of nodes in the spanning
    // tree and update the heap.
    Node* v1 = e->Src(); 
    neighbors.clear(); g->Neighbors(*v1, neighbors);
    for (auto edge: neighbors)
    {
      Node* v2 = edge->Dest(); 
      float cost = edge->Weight();
      if ( cost < dist[v2->GetValue()])
      {
        dist[v2->GetValue()] = cost;
        edges[v2->GetValue()] = v1;
        heap.push(edge);
      }
    }
  }
}

// set_dist_edges sets every dist to the largest value possible until we discover a way
// to link a node to the spanning tree.
void PrimJarnikMST::set_dist_edges(const int nvert) 
{
  for (int i; i < g->V(); ++i)
    {
      dist[i] = numeric_limits<float>::infinity();
      edges[i] = nullptr;
    }
}

// MSTCost returns the cost of the mst.
float PrimJarnikMST::MSTCost() const
{
  float cost = 0.0;
  for (auto edge: mst)
    cost += edge->Weight();
  return cost;
}

// Ouptut semantics for the PrimJarnikMST
ostream& operator<<(ostream& out, const PrimJarnikMST& pjm)
{
  out << "MST Cost: " << pjm.MSTCost() << endl; 
  out << "MST Edges: " << endl;
  for (auto edge: pjm.mst)
    out << *edge << endl;
  return out;
}
