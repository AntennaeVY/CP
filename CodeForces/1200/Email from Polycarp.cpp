#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    string s, t;
    cin >> s >> t;

    int index = 0;
    bool ans = true;

    for (int i = 0; i < t.size(); i++) {
      if (index < s.size() && s[index] == t[i])
        index++;
      else if (index == 0 || s[index - 1] != t[i]) {
        ans = false;
        break;
      }
    }

    if (ans && index == s.size())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}