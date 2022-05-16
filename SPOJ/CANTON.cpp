#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, i;
    cin >> n;

    for (i = 1; n > i * (i + 1) / 2; i++)
      ;

    cout << "TERM " << n << " IS ";
    int diff = i * (i + 1) / 2 - n;

    if (i & 1) {
      cout << 1 + diff << "/" << i - diff << endl;
    } else {
      cout << i - diff << "/" << 1 + diff << endl;
    }
  }
}