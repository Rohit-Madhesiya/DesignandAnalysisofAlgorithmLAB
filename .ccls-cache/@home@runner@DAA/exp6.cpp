
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixMultiply(vector<vector<int>> A,
                                   vector<vector<int>> B) {
  int n = A.size();
  vector<vector<int>> C(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

int main() {
  vector<vector<int>> A = {{1, 2, 3}, {5, 6, 7}, {3, 2, 1}};
  vector<vector<int>> B = {{1, 2, 3}, {5, 6, 7}, {3, 2, 1}};
  vector<vector<int>> C = matrixMultiply(A, B);
  cout << "Result: " << endl;
  for (int i = 0; i < C.size(); i++) {
    for (int j = 0; j < C[i].size(); j++) {
      cout << " " << C[i][j];
    }
    cout << endl;
  }
}
