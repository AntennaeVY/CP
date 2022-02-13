#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& a, int start, int end) {
  if (start >= end) {
    return;
  }

  int mid = (start + end) / 2;

  mergeSort(a, start, mid);
  mergeSort(a, mid + 1, end);

  // merge();
  int i = 0, j = 0, k = start;
  int n1 = mid - start + 1;
  int n2 = end - mid;

  vector<int> l(n1);
  vector<int> r(n2);

  for (int e{}; e < n1; e++) {
    l[e] = a[start + e];
  }

  for (int e{}; e < n2; e++) {
    r[e] = a[mid + 1 + e];
  }

  while (i < n1 && j < n2) {
    if (l[i] < r[j]) {
      a[k++] = l[i++];
    } else {
      a[k++] = r[j++];
    }
  }
  while (i < n1) a[k++] = l[i++];
  while (j < n2) a[k++] = r[j++];
}

int main() {
  vector<int> test{3, 4, 6, 7, 8, 10, 20, 5};
  mergeSort(test, 0, test.size() - 1);

  for (auto i : test) {
    cout << i << " ";
  }
}