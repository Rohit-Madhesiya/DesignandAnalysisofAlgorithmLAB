#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Activity {
  int start, finish;
};

bool activityCompare(Activity s1, Activity s2) {
  return (s1.finish < s2.finish);
}

void printMaxActivities(Activity act[], int n) {
  sort(act, act + n, activityCompare);
  int i = 0;
  cout << "Following activities are selected: " << endl;
  cout << "(" << act[i].start << ", " << act[i].finish << "), ";
  for (int j = 1; j < n; j++) {
    if (act[j].start >= act[i].finish) {
      cout << "(" << act[j].start << ", " << act[j].finish << "), ";
      i = j;
    }
  }
}

int main() {
  Activity act[] = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
  int n = sizeof(act) / sizeof(act[0]);
  printMaxActivities(act, n);
}