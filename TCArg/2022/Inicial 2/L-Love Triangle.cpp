#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);

  for (int i{}; i < n; i++) {
    cin >> a[i + 1];
  }

  string ans = "NO";

  for (int i{}; i < n; i++) {
    if (a[a[a[i + 1]]] == i + 1) ans = "YES";
  }

  cout << ans << endl;
}