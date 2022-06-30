#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long s;
  cin >> n >> s;

  vector<int> a(n);

  for (int i{}; i < n; i++) {
    cin >> a[i];
  }

  long long sum = 0, l = 0, mn = INT_MAX;

  for (int r{}; r < n; r++) {
    sum += a[r];

    while (sum - a[l] >= s) {
      sum -= a[l];
      l++;
    }

    if (sum >= s) {
      mn = min(mn, r - l + 1);
    }
  }

  cout << (mn == INT_MAX ? -1 : mn) << endl;
}