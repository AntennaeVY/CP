#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);

  for (auto &it : a) {
    cin >> it;
  }

  a.push_back(int(2e9));
  n++;

  for (auto &it : b) {
    cin >> it;
  }

  int i = 0, j = 0;

  long long ans = 0, cnt = 0;

  while (i < n && j < m) {
    if (a[i] == b[j]) {
      cnt++;
      i++;
    } else if (a[i] > b[j]) {
      ans += cnt;
      j++;

      while (b[j] == b[j - 1] && j < m) {
        ans += cnt;
        j++;
      }

      cnt = 0;

    } else {
      i++;
    }
  }

  cout << ans << endl;
}