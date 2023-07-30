#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  set<string> s;

  for (int i{}; i < n; i++) {
    string x;
    cin >> x;

    if (s.count(x))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;

    s.insert(x);
  }
}