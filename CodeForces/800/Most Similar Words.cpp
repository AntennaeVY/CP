#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    int min = 1e9;

    vector<string> a(n);

    for (int i{}; i < n; i++) {
      cin >> a[i];
    }

    for (int i{}; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        int sum = 0;

        for (int k{}; k < m; k++) {
          sum += abs((int)a[i][k] - (int)a[j][k]);
        }

        min = sum < min ? sum : min;
      }
    }

    cout << min << endl;
  }
}