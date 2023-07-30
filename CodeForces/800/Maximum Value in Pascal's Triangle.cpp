#include <bits/stdc++.h>
using namespace std;

int main() {
  int line;
  cin >> line;

  int ans = 0;
  int prev = 1;

  if (line == 0) {
    cout << 1;
    return 0;
  }

  for (int i{}; i < line; i++) {
    prev = prev * (line - i) / (i + 1);

    ans = max(ans, prev);
  }

  cout << ans;
}