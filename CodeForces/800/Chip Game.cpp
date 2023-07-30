#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    if ((n + m) % 2)
      cout << "Burenka" << endl;
    else
      cout << "Tonya" << endl;
  }
}