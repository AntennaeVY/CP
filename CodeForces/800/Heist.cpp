#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int i{}; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  long long sum = 0;

  for (int i{}; i < n - 1; i++) {
    if (a[i] != a[i + 1] - 1) {
      sum += a[i + 1] - a[i] - 1;
    }
  }

  cout << sum;
}