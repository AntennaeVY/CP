#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    cout << (n * (k / (n - 1)) + (k % (n - 1) == 0 ? -1 : k % (n - 1))) << endl;
  }
}