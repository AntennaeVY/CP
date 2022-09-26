#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;

    long long ans = 0;

    for (int i = 1; i <= 9; i++) {
      long long ten = 1, curr = i;
      for (int j = 0; j < 9; j++) {
        if (curr <= n) ans++;

        ten *= 10;
        curr += i * ten;
      }
    }

    cout << ans << endl;
  }
}