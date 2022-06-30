#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b;
    map<int, int> m;

    for (int i{}; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }

    sort(a.begin(), a.end());

    for (auto x : m) {
      if (x.second >= k) b.push_back(x.first);
    }

    if (b.empty()) {
      cout << -1 << endl;
      continue;
    }

    b.push_back(-1);

    int cnt = 1;
    int start = 0, startM = 0, end = 0, endM = 0;

    for (int i{}; i < b.size() - 1; i++) {
      if (cnt == 1) start = b[i];

      if (b[i + 1] == b[i] + 1)
        cnt++;
      else {
        end = b[i];

        if (end - start >= endM - startM) {
          startM = start;
          endM = end;
        }

        cnt = 1;
      }
    }

    cout << startM << " " << endM << endl;
  }
}