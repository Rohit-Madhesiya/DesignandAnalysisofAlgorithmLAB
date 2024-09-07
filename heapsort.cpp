#include <chrono>
#include <cstdlib>
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {145, 40, 25, 65, 12, 48, 18, 1, 100, 27, 73, 45, 9, 30};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Array before sorting: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  auto start = std::chrono::high_resolution_clock::now();
  heapSort(arr, n);
  auto finish = std::chrono::high_resolution_clock::now();
  cout << "Using Heap Sort Algorithm:" << endl;
  cout << "Array after sorting: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  cout
      << std::chrono::duration_cast<chrono::nanoseconds>(finish - start).count()
      << " nanoseconds\n";

  return 0;
}