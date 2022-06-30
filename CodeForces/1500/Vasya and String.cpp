#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  vector<char> alphabet = {'a', 'b'};

  int mx = -1;

  for (int i{}; i < 2; i++) {
    int l = 0, cnt = 0;

    for (int r{}; r < n; r++) {
      if (s[r] != alphabet[i]) cnt++;

      while (cnt > k) {
        if (s[l] != alphabet[i]) cnt--;

        l++;
      }

      mx = max(r - l + 1, mx);
    }
  }

  cout << mx << endl;
}