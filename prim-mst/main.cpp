#include <iostream>
#include "prim_mst.h"

using namespace std;

int main()
{
  // Read in a graph
  Graph g("data.txt");
  Graph* gptr = &g; 
  
  // Pick a starting node
  Node start_node(1); 

  // Run an instance of the Jarnik-Prim MST algorithm
  PrimJarnikMST* alg = new PrimJarnikMST(gptr, start_node);
  cout << *alg << endl;
}
