#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  float s = 0;

  for (int i = 0; i < n; i++) {
    s += 1.0 / (n - i);
  }

  cout << s << endl;
}