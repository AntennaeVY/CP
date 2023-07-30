
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b, x;
    cin >> a >> b >> x;

    bool condition = abs(a - b) % x == 0 && abs(a - b) >= 2;

    cout << (condition ? "Yes" : "No") << endl;
  }
}