#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

#define V 5

struct Edge {
  int src, dest, weight;
};

void printArr(int dist[], int n) {
  cout << "Vertex Distance from Source" << endl;
  for (int i = 0; i < n; i++)
    cout << i << " " << dist[i] << endl;
}

void BellmanFord(vector<Edge> edges, int src) {
  int dist[V];
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;
  dist[src] = 0;

  for (int i = 1; i < V - 1; i++) {
    for (Edge edge : edges) {
      int u = edge.src;
      int v = edge.dest;
      int weight = edge.weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }

  for (Edge edge : edges) {
    int u = edge.src;
    int v = edge.dest;
    int weight = edge.weight;
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
      cout << "Graph contains negative weight cycle" << endl;
      return;
    }
  }

  printArr(dist, V);
}

int main() {
  vector<Edge> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
                        {1, 4, 2},  {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
  BellmanFord(edges, 0);
  return 0;
}