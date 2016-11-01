#include <vector>
#include <queue>
#include "graph.h"

using namespace std;

// Comapres two edges and returns true if a is less than b, false otherwise.
class edgeComp {
  public:
    edgeComp() {};
    bool operator() (const Edge* a, const Edge* b) const {
      return (a->Weight() < b->Weight());
    }
};

// A simpler name for prioirty queue
typedef priority_queue<Edge*, vector<Edge*>, edgeComp > edge_pqueue;

// PrimJarnikMST implements the Prim MST algorithm. It uses a priority queue
// to maintain the minimum edge reachable from any node in the spanning tree.
// To run the algorithm we need to have an initialized graph and a starting
// Node that is in the graph g. The algorithm is run when the instance of 
// PrimJarnikMST is constructed.
class PrimJarnikMST {
  public:
    PrimJarnikMST(const Graph* g, const Node& start);
    ~PrimJarnikMST();
    // Returns the mst cost
    float MSTCost() const;
    friend ostream& operator<<(ostream&, const PrimJarnikMST& pjm);
  private:
    // initializes the dist to have the largest value possible and edges
    // to nullptr.
    void set_dist_edges(const int nvert);

    // Graph to run the PrimJarnikMST algorthm on
    const Graph* g;

    // the distances from the source to each node
    vector<float> dist;

    // indicates which vertex in the tree an edge is closest to
    vector<Node*> edges;

    // the minimum spanning tree
    vector<Edge*> mst;

    // heap of unifinshed edges 
    edge_pqueue heap;
};

ostream& operator<<(ostream& out, const PrimJarnikMST& pjm);
