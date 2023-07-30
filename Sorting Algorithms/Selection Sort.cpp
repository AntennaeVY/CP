#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void selectionSortRecursive(vector<int>& arr, int start) {
  if (start == arr.size() - 1) {
    return;
  }

  int size = int(arr.size());

  for (int i = start; i < size; i++) {
    if (arr[i] < arr[start]) {
      swap(arr[i], arr[start]);
    }
  }

  selectionSortRecursive(arr, start + 1);
}

void selectionSort(vector<int>& arr) {
  int size = int(arr.size());

  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      if (arr[j] < arr[i]) {
        swap(arr[j], arr[i]);
      }
    }
  }
}

int main() {
  vector<int> arr{6, 4, 2, 1, 7, 9};

  // selectionSort(arr);
  selectionSortRecursive(arr, 0);

  for (auto e : arr) {
    cout << e << " ";
  }
}
