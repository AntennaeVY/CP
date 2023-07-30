#include <bits/stdc++.h>
using namespace std;

bool isprime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }

  return true;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, sum = 0;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
      sum += i;
    }

    if (!isprime(sum)) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
    } else {
      bool first = true;

      cout << n - 1 << endl;
      for (int i = 1; i <= n; i++) {
        if (a[i - 1] % 2 && first) {
          first = false;
          continue;
        }

        cout << i << " ";
      }
    }

    cout << endl;
  }
}