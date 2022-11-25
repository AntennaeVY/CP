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

    int ans = INT_MAX;

    for (int i = 2; i <= 7; i++) {
      int l = 0;
      map<char, int> m;

      for (int r = 0; r < n; r++) {
        m[s[r]]++;

        while (r - l + 1 > i) {
          m[s[l]]--;
          l++;
        }
        
        if (r-l+1 == i && m['b'] < m['a'] && m['c'] < m['a']) {
        	ans = min(ans, i);
        }
      }
    }
    
	cout << (ans == INT_MAX ? -1 : ans) << endl;
  }
}