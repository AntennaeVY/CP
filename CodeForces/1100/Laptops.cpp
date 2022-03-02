#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; }

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> l(n);

  for (int i{}; i < n; i++) {
    cin >> l[i].first;
    cin >> l[i].second;
  }

  sort(l.begin(), l.end(), cmp);

  string ans = "Poor Alex";

  for (int i{}; i < n - 1; i++) {
    if (l[i].first < l[i + 1].first && l[i].second > l[i + 1].second) {
      ans = "Happy Alex";
      break;
    }
  }

  cout << ans;
}