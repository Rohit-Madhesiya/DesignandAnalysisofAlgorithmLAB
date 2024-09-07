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

int partition(int arr[], int start, int end) {
  int index = 0, pivot = arr[end], pivotIndex;
  int temp[end - start + 1];
  for (int i = start; i <= end; i++) {
    if (arr[i] < pivot) {
      temp[index] = arr[i];
      index++;
    }
  }
  temp[index] = pivot;
  index++;
  for (int i = start; i < end; i++) {
    if (arr[i] > pivot) {
      temp[index] = arr[i];
      index++;
    }
  }
  index = 0;
  for (int i = start; i <= end; i++) {
    if (arr[i] == pivot)
      pivotIndex = i;
    arr[i] = temp[index];
    index++;
  }
  return pivotIndex;
}
void quick_sort(int arr[], int start, int end) {
  if (start < end) {
    int partIndex = partition(arr, start, end);
    quick_sort(arr, start, partIndex - 1);
    quick_sort(arr, partIndex + 1, end);
  }
}

void merge(int arr[], int left, int mid, int right) {
  int subArr1 = mid - left + 1;
  int subArr2 = right - mid;
  int leftArr[subArr1];
  int rightArr[subArr2];
  for (int i = 0; i < subArr1; i++)
    leftArr[i] = arr[left + i];
  for (int j = 0; j < subArr2; j++)
    rightArr[j] = arr[mid + 1 + j];
  int index1 = 0, index2 = 0;
  int indexMerge = left;
  while (index1 < subArr1 && index2 < subArr2) {
    if (leftArr[index1] <= rightArr[index2]) {
      arr[indexMerge] = leftArr[index1];
      index1++;
    } else {
      arr[indexMerge] = rightArr[index2];
      index2++;
    }
    indexMerge++;
  }
  while (index1 < subArr1) {
    arr[indexMerge] = leftArr[index1];
    index1++;
    indexMerge++;
  }
  while (index2 < subArr2) {
    arr[indexMerge] = rightArr[index2];
    index2++;
    indexMerge++;
  }
}
void merge_sort(int arr[], int start, int end) {
  if (start >= end)
    return;
  int mid = start + (end - start) / 2;
  merge_sort(arr, start, mid);
  merge_sort(arr, mid + 1, end);
  merge(arr, start, mid, end);
}

int main() {
  cout << "Enter length of Array: ";
  int n;
  n = input();
  int arr[n];
  inputArray(arr, n);
  while (1) {
    cout << "Enter Algorithm wants to use:\n 1: Quick Sort\n2: Merge "
            "Sort\n-1: To Exit\n Choose: ";
    int choice = input();

    switch (choice) {
    case 1: {
      cout << "Before Sorting: ";
      output(arr, n);
      int temp[n];
      for (int i = 0; i < n; i++)
        temp[i] = arr[i];
      auto start = std::chrono::high_resolution_clock::now();
      quick_sort(temp, 0, n - 1);
      auto finish = std::chrono::high_resolution_clock::now();
      cout << "After Quick Soring: ";
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
      merge_sort(temp, 0, n - 1);
      auto finish = std::chrono::high_resolution_clock::now();
      cout << "After Merge Soring: ";
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