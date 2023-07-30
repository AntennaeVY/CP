#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    bool rev = s[0] > s.back();

    vector<int> path;
    vector<vector<int>> indx(26, vector<int>(0));
    char first = s[0], last = s.back();
    int cost = abs(first - last);

    for (int i = 0; i < s.size(); i++) {
      indx[s[i] - 'a'].push_back(i + 1);
    }

    sort(s.begin(), s.end());

    for (int i{}; i < s.size(); i++) {
      bool condition;

      if (!rev)
        condition = s[i] >= first && s[i] <= last;
      else
        condition = s[i] <= first && s[i] >= last;

      if (condition) {
        path.push_back(indx[s[i] - 'a'].back());
        indx[s[i] - 'a'].pop_back();
      }
    }

    cout << cost << " " << path.size() << endl;
    cout << 1 << " ";

    if (rev) {
      for (int i = path.size() - 1; i >= 0; i--) {
        if (path[i] != 1 && path[i] != s.size()) {
          cout << path[i] << " ";
        }
      }
    } else {
      for (auto i : path) {
        if (i != 1 && i != s.size()) cout << i << " ";
      }
    }

    cout << s.size();
    cout << endl;
  }
}