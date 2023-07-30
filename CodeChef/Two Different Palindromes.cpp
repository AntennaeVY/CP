#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;

    if ((a % 2 && b % 2)) {
      cout << "No" << endl;
      continue;
    }

    cout << "Yes" << endl;
  }
}