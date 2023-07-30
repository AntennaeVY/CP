#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> logs(n);

    for (int i{}; i < n; i++) {
      cin >> logs[i];
    }

    sort(logs.rbegin(), logs.rend());

    bool loser = true;

    for (int i{}; i < n; i++) {
      if (logs[i] == 1) {
        break;
      }

      if (logs[i] % 2 == 0) {
        loser = loser ^ (logs[i] % 2 == 0);
      } else {
        loser = !loser ^ ((logs[i] - 1) % 2 == 0);
      }
    }

    if (loser) {
      cout << "maomao90" << endl;
    } else {
      cout << "errorgorn" << endl;
    }
  }
}