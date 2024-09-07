#include <iostream>
using namespace std;

int input() {
  int in;
  cin >> in;
  return in;
}
void inputArray(int arr[], int n) {
  cout << "Enter Elements: \n";
  for (int i = 0; i < n; i++) {
    cout << "Element[" << i << "]: ";
    cin >> arr[i];
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
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
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

  cout << "Enter Algorithm wants to use:\n 1: Insertion Sort\n2: Bubble "
          "Sort\n3: Selection Sort\n Choose: ";
  int choice = input();

  switch (choice) {
  case 1:
    insertion_sort(arr, n);
    break;
  case 2:
    bubble_sort(arr, n);
    break;
  case 3:
    selection_sort(arr, n);
    break;
  default:
    cout << "Wrong Option... ";
    exit(0);
  }
  output(arr, n);

  return 0;
}