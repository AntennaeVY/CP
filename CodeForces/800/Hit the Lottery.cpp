#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;

  vector<int> b = {100, 20, 10, 5, 1};

  for (int i{}; i < 5; i++) {
    ans += n / b[i];
    n = n % b[i];
  }

  cout << ans << endl;
}