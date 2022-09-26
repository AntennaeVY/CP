#include <bits/stdc++.h>
using namespace std;

vector<int> x(1e6);

int main() {
  int t;
  cin >> t;

  x[0] = 0;
  for (int i = 1; i < 1e6; i++) {
    x[i] = x[i - 1] ^ (i - 1);
  }

  while (t--) {
    int a, b;
    cin >> a >> b;

    if (x[a] == b)
      cout << a << endl;
    else if ((x[a] ^ b) != a)
      cout << a + 1 << endl;
    else
      cout << a + 2 << endl;
  }
}