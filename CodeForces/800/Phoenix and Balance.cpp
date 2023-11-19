#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int ans = 0;

    for (int i=1; i <= n; i++) {
      if (i == n || i < n/2) {
        ans += (1 << i);
      } else {
        ans -= (1 << i);
      }
    }
    
    cout << ans << endl;
  }
}