#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    vector<vector<int>> v(26, vector<int>(0));
    vector<int> path;
    char start = s[0], end = s.back();
    bool rev = start > end;

    for (int i{}; i < s.size(); i++) {
      v[s[i] - 97].push_back(i);
    }

    cout << abs(start - end) << " ";

    sort(s.begin(), s.end());

    auto st = find(s.begin(), s.end(), start);

    bool flag = false;

    if (rev) {
      for (auto i = st; i != prev(s.begin()); i = prev(i)) {
        if (*i != end && flag) break;

        path.push_back(v[*(i)-97].back());
        v[*(i)-97].pop_back();

        if (*i == end) flag = true;
      }
    } else {
      for (auto i = st; i != s.end(); i = next(i)) {
        if (*i != end && flag) break;

        path.push_back(v[*(i)-97].back());
        v[*(i)-97].pop_back();

        if (*i == end) flag = true;
      }
    }

    cout << path.size() << endl;

    cout << 1 << " ";

    for (auto i : path) {
      if (i != s.size() - 1 && i != 0) cout << i + 1 << " ";
    }

    cout << s.size() << endl;
  }
}