#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    map<string, int> m;
    vector<vector<string>> ps(3);
    vector<int> p(3, 0);

    for (int i{}; i < 3; i++) {
      for (int j{}; j < n; j++) {
        string s;
        cin >> s;

        ps[i].push_back(s);

        m[s]++;
      }
    }

    for (int i{}; i < 3; i++) {
      for (int j{}; j < n; j++) {
        if (m[ps[i][j]] == 1)
          p[i] += 3;
        else if (m[ps[i][j]] == 2)
          p[i] += 1;
      }
    }

    for (auto x : p) {
      cout << x << " ";
    }

    cout << endl;
  }
}