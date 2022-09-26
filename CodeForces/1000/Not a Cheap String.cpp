#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int p;
    cin >> p;

    map<char, int> m;
    int sum = 0;
    string w = "";

    string t(s);
    sort(t.begin(), t.end());

    for (int i{}; i < t.size(); i++) {
      if (sum + t[i] - 96 > p) m[t[i]]++;

      sum += t[i] - 96;
    }

    for (int i{}; i < s.size(); i++) {
      if (m[s[i]] > 0) {
        m[s[i]]--;
        continue;
      }

      w += s[i];
    }

    cout << w << endl;
  }
}