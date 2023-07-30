#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int s, n;
  cin >> s >> n;

  vector<pair<int, int>> dragons;

  for (int i{}; i < n; i++) {
    int x, y;
    cin >> x >> y;
    dragons.push_back(make_pair(x, y));
  }

  sort(dragons.begin(), dragons.end());

  for (int i{}; i < n; i++) {
    if (s > dragons[i].first) {
      s += dragons[i].second;
    } else {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}