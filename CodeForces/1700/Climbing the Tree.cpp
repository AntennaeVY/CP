#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int q;
    cin >> q;

    long long MIN = -1, MAX = -1;

    while (q--) {
      int type;
      cin >> type;

      long long a, b;
      cin >> a >> b;

      long long d = a - b;

      if (type == 1) {
        int n;
        cin >> n;

        long long mn = 1;
        long long mx = d * (n - 1) + a;
        
        if (n > 1)
        	mn = d * (n - 1) + b + 1;
        	
        if (MIN == -1) {
          MIN = mn;
          MAX = mx;

          cout << 1 << " ";
        } else {
          if (mx < MIN || mn > MAX) {
            cout << 0 << " ";
            continue;
          }

          MIN = max(mn, MIN);
          MAX = min(mx, MAX);

          cout << 1 << " ";
        }
      }

      if (type == 2) {
        if (MIN == -1) {
          cout << -1 << " ";
          continue;
        }

        // check days needed
        long long mn = 1 + max(0LL, (MIN - a + d - 1) / d);
        long long mx = 1 + max(0LL, (MAX - a + d - 1) / d);

        if (mn != mx) {
          cout << -1 << " ";
          continue;
        }

        cout << mn << " ";
      }
    }

    cout << endl;
  }
}