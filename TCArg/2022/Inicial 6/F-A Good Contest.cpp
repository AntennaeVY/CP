#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  bool ans = false;

  for (int i{}; i < n; i++) {
    string name;
    cin >> name;

    int before, after;
    cin >> before >> after;

    if (before >= 2400 && after > before) ans = true;
  }

  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}