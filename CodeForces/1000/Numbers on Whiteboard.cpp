#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    cout << 2 << endl;
    cout << n - 1 << " " << n << endl;

    for (int i = n; i > 2; i--) {
      cout << i - 2 << " " << i << endl;
    }
  }
}