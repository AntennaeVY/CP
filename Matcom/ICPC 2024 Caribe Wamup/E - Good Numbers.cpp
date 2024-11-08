#include <bits/stdc++.h>
using namespace std;

int main() {
  long long l, r;
  cin >> l >> r;

  long long L = -1, R = -1;

  while (l <= r) {
    if (L != -1 && R != -1) break;

    if (L == -1) {
      long long sum = 0;

      for (long long i = 2; i * i <= l; i++) {
        if (l % i) continue;

        if (i * i != l) sum += l / i;

        sum += i;

        if (sum > l) break;
      }

      if (sum > l)
        L = l;
      else
        l++;
    }

    if (R == -1) {
      long long sum = 0;

      for (long long i = 2; i * i <= r; i++) {
        if (r % i) continue;

        if (i * i != r) sum += r/ i;

        sum += i;

        if (sum > r) break;
      }

      if (sum > r)
        R = r;
      else
        r--;
    }
  }
  
  cout << L << " " << R << endl;
}