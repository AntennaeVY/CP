#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a, int start) {
  int ans = 0;
  int n = a.size();
  int j = 1;

  for (int i = 0; i < n; i++) {
    if (a[i] == start && i%2 == 0 || a[i] != start && i%2 == 1) continue;

    for (j = max(i+1, j); j < n; j++) {
      if (a[j] == start && i%2 == 0 || a[j] != start && i%2 == 1) {
        swap(a[j], a[i]);
        ans += j - i;
        break;
      }
    }
  }
  
  return ans;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int odd = 0, even = 0;
    vector<int> a(n);
    for (auto &ai : a) {
      int x;
      cin >> x;

      x % 2 ? odd++ : even++;
      ai = x % 2;
    }

    if (abs(odd - even) > 1) {
      cout << -1 << endl;
      continue;
    }

    if (even > odd)
    	cout << solve(a, 0) << endl;
    else if (odd > even)
    	cout << solve(a, 1) << endl;
    else
    	cout << min(solve(a, 1), solve(a, 0)) << endl;
  }
}