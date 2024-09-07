#include <iostream>
using namespace std;

#define V 4

void printSolution(int reach[][V]) {
  cout << "Following matrix is transitive closure of the given graph" << endl;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      cout << reach[i][j] << " ";
    cout << endl;
  }
}

void transitiveClosure(int graph[][V]) {
  int reach[V][V];
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      reach[i][j] = graph[i][j];
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
      }
    }
  }
  printSolution(reach);
}

int main() {
  int graph[V][V] = {{1, 1, 0, 1}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}};
  transitiveClosure(graph);
  return 0;
}