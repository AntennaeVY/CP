#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> freq = {0, 0, 0};

    for (int i{}; i < n; i++) {
      int x;
      cin >> x;

      freq[x]++;
    }

    if (freq[1] % 2) {
      cout << "NO" << endl;
      continue;
    }

    if (freq[1] % 2 == 0 && freq[1] != 0) {
      cout << "YES" << endl;
      continue;
    }

    if (freq[1] == 0 && freq[2] % 2) {
      cout << "NO" << endl;
      continue;
    }
  }
}