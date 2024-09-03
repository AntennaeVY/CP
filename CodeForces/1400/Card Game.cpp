#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    char trump;
    cin >> trump;

    map<char, vector<int>> m;
    for (int i = 0; i < 2*n; i++) {
      string s;
      cin >> s;

      m[s[1]].push_back(s[0] - 48);
    }

    int odd = 0;

    for (auto &[r, v] : m) {
      sort(v.begin(), v.end());
      if (r == trump) continue;

      odd += v.size() % 2;
    }

    if (odd > m[trump].size()) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }

    for (auto &[r, v] : m) {
      if (r == trump) continue;

      if (v.size() % 2) {
        cout << v.back() << r << " " << m[trump].back() << trump << endl;
        v.pop_back();
        m[trump].pop_back();
      }

      for (int i = 1; i < v.size(); i += 2) {
        cout << v[i - 1] << r << " " << v[i] << r << endl;
      }
    }

    for (int i = 1; i < m[trump].size(); i += 2)
      cout << m[trump][i - 1] << trump << " " << m[trump][i] << trump << endl;
  }
}