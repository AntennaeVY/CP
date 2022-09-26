#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> w(n), h(n);
  for (int i{}; i < n; i++) {
    cin >> w[i];
    cin >> h[i];
  }

  int mx = max(w[0], h[0]);
  string ans = "YES";

  for (int i = 1; i < n; i++) {
    int num = max(w[i], h[i]) > mx ? min(w[i], h[i]) : max(w[i], h[i]);

    if (num > mx) ans = "NO";

    mx = num;
  }

  cout << ans << endl;
}