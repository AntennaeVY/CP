#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;

    cout << min(x, n - x) << endl;
  }
}