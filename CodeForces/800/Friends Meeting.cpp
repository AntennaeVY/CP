#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int mx = max(a, b);
  a = min(a, b);
  b = mx;

  if ((b - a) % 2 == 0)
    cout << ((b - a) / 2) * ((b - a) / 2 + 1) << endl;
  else
    cout << ((b - a) / 2) * ((b - a) / 2 + 1) / 2 +
                ((b - a) / 2 + 1) * ((b - a) / 2 + 2) / 2
         << endl;
}