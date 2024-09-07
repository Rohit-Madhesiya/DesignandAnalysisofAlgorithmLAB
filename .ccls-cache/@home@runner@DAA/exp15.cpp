#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
  int src, dest, weight;
};

class Graph {
public:
  int V, E;
  Edge *edge;
};

class subset {
public:
  int parent;
  int rank;
};

int find(subset subsets[], int i);
void Union(subset subsets[], int x, int y);
void KruskalMST(Graph graph);

int main() {
  int V = 4;
  int E = 5;
  Graph graph;
  graph.V = V;
  graph.E = E;
  graph.edge = new Edge[E];

  graph.edge[0].src = 0;
  graph.edge[0].dest = 1;
  graph.edge[0].weight = 10;

  // Add other edges

  KruskalMST(graph);

  return 0;
}

int find(subset subsets[], int i) {
  if (subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void Union(subset subsets[], int x, int y) {
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);

  if (subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
  else if (subsets[xroot].rank > subsets[yroot].rank)
    subsets[yroot].parent = xroot;
  else {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

void KruskalMST(Graph graph) {
  int V = graph.V;
  Edge result[V];
  int e = 0;
  int i = 0;

  sort(graph.edge, graph.edge + graph.E,
       [](Edge a, Edge b) { return a.weight < b.weight; });

  subset *subsets = new subset[(V * sizeof(subset))];

  for (int v = 0; v < V; v++) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  while (e < V - 1 && i < graph.E) {
    Edge next_edge = graph.edge[i++];

    int x = find(subsets, next_edge.src);
    int y = find(subsets, next_edge.dest);

    if (x != y) {
      result[e++] = next_edge;
      Union(subsets, x, y);
    }
  }

  cout << "Following are the edges in the constructed MST" << endl;
  for (i = 0; i < e; i++) {
    cout << result[i].src << " - " << result[i].dest << endl;
  }

  return;
}