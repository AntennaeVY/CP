#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n, 0);

  for (int i{}; i < n; i++) {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  vector<int> freq_t(n + 2, 0);

  for (int i{}; i < q; i++) {
    int l, r;
    cin >> l >> r;

    freq_t[l]++;
    freq_t[r + 1]--;
  }

  vector<int> ps_freq(n + 3, 0);

  for (int i = 0; i < n + 2; i++) {
    ps_freq[i + 1] = ps_freq[i] + freq_t[i];
  }

  sort(ps_freq.rbegin(), ps_freq.rend());

  long long sum = 0;

  for (int i{}; i < n; i++) {
    sum += 1LL * a[i] * ps_freq[i];
  }

  cout << sum;
}