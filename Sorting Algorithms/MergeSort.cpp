#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
  int leftElems = mid - left + 1;
  int rightElems = right - mid;

  vector<int> L(leftElems), R(rightElems);

  for (int i{}; i < leftElems; i++) {
    L[i] = arr[left + i];
  }

  for (int i{}; i < rightElems; i++) {
    R[i] = arr[mid + i + 1];
  }

  int i = 0, j = 0, k = left;

  while (i < leftElems && j < rightElems) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }

  while (i < leftElems) arr[k++] = L[i++];

  while (j < rightElems) arr[k++] = R[j++];
}

void mergesort(vector<int> &arr, int left, int right) {
  if (left >= right) return;

  int mid = left + (right - left) / 2;

  mergesort(arr, left, mid);
  mergesort(arr, mid + 1, right);

  // Merge
  merge(arr, left, mid, right);
}

int main() {
  vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  for (auto x : arr) {
    cout << x << " ";
  }

  cout << endl;

  mergesort(arr, 0, arr.size() - 1);

  for (auto x : arr) {
    cout << x << " ";
  }
}