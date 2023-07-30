#include <iostream>
#include <vector>
using namespace std;

// First try
void insertionSort(vector<int> &arr) {
  int size = int(arr.size());

  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      swap(arr[i], arr[i - 1]);

      for (int j = i - 1; j > 0; j--) {
        if (arr[j] < arr[j - 1]) {
          swap(arr[j], arr[j - 1]);
        } else {
          break;
        }
      }
    }
  }
}

// Better approach
void insertionSort2(vector<int> &arr) {
  int size = arr.size();

  for (int i = 1; i < size; i++) {
    int key = arr[i];

    int j = i - 1;

    while (key < arr[j] && j >= 0) {
      swap(arr[j], arr[j + 1]);

      /*
              arr[j+1] = arr[j];
      */

      j--;
    }
    // arr[j+1] = key;
  }
}

int main() {
  vector<int> arr{7, 8, 9, 0, 1, 2};

  insertionSort(arr);

  for (auto e : arr) {
    cout << e << " ";
  }
}