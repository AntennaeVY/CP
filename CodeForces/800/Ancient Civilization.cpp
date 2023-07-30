#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n, l;
    cin >> n >> l;

    vector<int> v(n);

    for (int i{}; i < n; i++) {
      int x;
      cin >> v[i];
    }

    int ans = 0;

    for (int i = 1; i < (1 << l); i <<= 1) {
      int cnt = 0;

      for (auto x : v) {
        if (x & i) cnt++;
      }

      if (cnt > n / 2) {
        ans += i;
      }
    }

    cout << ans << endl;
  }
}