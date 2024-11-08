#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> suf(2, vector<int>(26));
    vector<vector<int>> pref(2, vector<int>(26));

    for (int i = n - 1; i >= 0; i--) {
      suf[i % 2][s[i] - 'a']++;
    }

    int ans = n;

    if (n % 2 == 0) {
      for (int i = 0; i < 2; i++) {
        int mx = 0;

        for (int j = 0; j < 26; j++) {
          mx = max(mx, suf[i][j]);
        }

        ans -= mx;
      }

      cout << ans << endl;
      continue;
    }

    for (int i = 0; i < n; i++) {
      suf[i % 2][s[i] - 'a'] -= 1;

      int curr = n;

      for (int j = 0; j < 2; j++) {
        int mx = 0;

        for (int k = 0; k < 26; k++) {
          mx = max(mx, pref[j][k] + suf[j ^ 1][k]);
        }
        
        curr -= mx;
      }
      
      ans = min(ans, curr);

      pref[i % 2][s[i] - 'a'] += 1;
    }

    cout << ans << endl;
  }
}