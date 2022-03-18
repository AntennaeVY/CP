#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> p(n), s(n), c(k);
  int cnt = 0;

  for (int i{}; i < n; i++) {
    cin >> p[i];
  }

  for (int i{}; i < n; i++) {
    cin >> s[i];
  }

  for (int i{}; i < k; i++) {
    cin >> c[i];
  }

  map<int, int> tps;

  for (int i{}; i < n; i++) {
    if (tps[s[i]] < p[i]) {
      tps[s[i]] = p[i];
    }
  }

  for (int i{}; i < k; i++) {
    if (tps[s[c[i] - 1]] > p[c[i] - 1]) {
      cnt++;
    }
  }

  cout << cnt;
}