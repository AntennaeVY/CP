#include <bits/stdc++.h>
using namespace std;

int main() {
  long long l, r;
  cin >> l >> r;

  vector<bool> is_prime(r + 1, true);

  int cnt = 0;

  for (long long i = 2; i <= r; i++) {
    if (!is_prime[i]) continue;

    if (i >= l) {
      string s = to_string(i);
      string t = to_string(i);

      reverse(t.begin(), t.end());

      if (s == t) cnt++;
    }

    for (long long j = i * i; j <= r; j += i) {
      is_prime[j] = false;
    }
  }

  cout << cnt << endl;
}