#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  vector<vector<int>> ans(46);

  for (int i{}; i < (1 << 9); i++) {
    int sum = 0;
    vector<int> subset;
    for (int j{}; j < 9; j++) {
      if (i & (1 << j)) {
        sum += j + 1;
        subset.push_back(j + 1);
      }
    }

    ans[sum] = subset;
  }

  while (t--) {
    int s;
    cin >> s;

    for (int i : ans[s]) {
      cout << i;
    }

    cout << endl;
  }
}