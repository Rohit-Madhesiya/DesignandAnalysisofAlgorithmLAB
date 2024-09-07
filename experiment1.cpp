#include <chrono>
#include <cstdlib>
#include <iostream>
using namespace std;

int input() {
  int in;
  cin >> in;
  return in;
}
void inputArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 1000;
  }
}
void output(int arr[], int n) {
  cout << "Elements are: [ ";
  for (int i = 0; i < n - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[n - 1] << " ]" << endl;
}

void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
void insertion_sort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int j, temp;
    j = i - 1;
    temp = arr[i];
    while (j >= 0 && temp < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}
void selection_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int ind = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[ind]) {
        ind = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[ind];
    arr[ind] = temp;
  }
}

int main() {
  cout << "Enter length of Array: ";
  int n;
  n = input();
  int arr[n];
  inputArray(arr, n);
  while (1) {
    cout << "Enter Algorithm wants to use:\n 1: Insertion Sort\n2: Bubble "
            "Sort\n3: Selection Sort\n-1: To Exit\n Choose: ";
    int choice = input();

    switch (choice) {
    case 1: {
      cout << "Before Sorting: ";
      output(arr, n);
      int temp[n];
      for (int i = 0; i < n; i++)
        temp[i] = arr[i];
      auto start = std::chrono::high_resolution_clock::now();
      insertion_sort(temp, n);
      auto finish = std::chrono::high_resolution_clock::now();

      cout << "After Insertion Soring: ";
      output(temp, n);
      cout << std::chrono::duration_cast<chrono::nanoseconds>(finish - start)
                  .count()
           << " nanoseconds\n";
    } break;
    case 2: {
      cout << "Before Sorting: ";
      output(arr, n);
      int temp[n];
      for (int i = 0; i < n; i++)
        temp[i] = arr[i];
      auto start = std::chrono::high_resolution_clock::now();
      bubble_sort(temp, n);
      auto finish = std::chrono::high_resolution_clock::now();
      cout << "After Bubble Soring: ";
      output(temp, n);
      cout << std::chrono::duration_cast<chrono::nanoseconds>(finish - start)
                  .count()
           << " nanoseconds\n";
    } break;
    case 3: {
      cout << "Before Sorting: ";
      output(arr, n);
      int temp[n];
      for (int i = 0; i < n; i++)
        temp[i] = arr[i];
      auto start = std::chrono::high_resolution_clock::now();
      selection_sort(temp, n);
      auto finish = std::chrono::high_resolution_clock::now();
      cout << "After Selection Soring: ";
      output(temp, n);
      cout << std::chrono::duration_cast<chrono::nanoseconds>(finish - start)
                  .count()
           << " nanoseconds\n";
    } break;
    default:
      exit(0);
    }
  }
  return 0;
}