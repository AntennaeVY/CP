#include <bits/stdc++.h>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) return 0;

    int ans = 0;

    for (int i = 0; i < n; i++) {
      ans += (n-i) * (n-i);
    }

    cout << ans << endl;
  }
}