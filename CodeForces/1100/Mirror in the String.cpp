#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s, ans;
    cin >> s;

    ans += s[0];

    for (int i = 1; i < n; i++) {
      if (s[i] <= s[i - 1]) {
        ans += s[i];
      } else {
      	break;
      }
    }
    
    string sh = s.substr(0,1) + s.substr(0,1);
    
    if (sh > ans)
    cout << ans << string(ans.rbegin(), ans.rend()) << endl;
    else
    cout << sh << endl;
  }
}