#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int left, int mid, int right) {
  int leftElems = mid - left + 1;
  int rightElems = right - mid;

  int inv = 0;

  vector<int> L(leftElems), R(rightElems);

  for (int i{}; i < leftElems; i++) {
    L[i] = arr[left + i];
  }

  for (int i{}; i < rightElems; i++) {
    R[i] = arr[mid + i + 1];
  }

  int i = 0, j = 0, k = left;

  while (i < leftElems && j < rightElems) {
    if (L[i] < R[j])
      arr[k++] = L[i++];
    else {
      arr[k++] = R[j++];

      // (i,j) => i < j && a[j] < a[i];
      inv += (leftElems - i);
    }
  }

  while (i < leftElems) arr[k++] = L[i++];

  while (j < rightElems) arr[k++] = R[j++];

  return inv;
}

int mergesort(vector<int> &arr, int left, int right) {
  if (left >= right) return 0;

  int mid = left + (right - left) / 2;

  int inv = 0;

  inv += mergesort(arr, left, mid);
  inv += mergesort(arr, mid + 1, right);

  // Merge
  inv += merge(arr, left, mid, right);

  return inv;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &it : a) {
      cin >> it;
    }

    cout << mergesort(a, 0, n - 1) << endl;
  }
}