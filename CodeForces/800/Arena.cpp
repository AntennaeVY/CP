#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    set<int> s;
    map<int, int> m;

    for (int i{}; i < n; i++) {
      int x;
      cin >> x;

      s.insert(x);
      m[x]++;
    }

    cout << n - m[*s.begin()] << endl;
  }
}