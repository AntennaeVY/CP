#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);

    for (int i{}; i < n; i++) {
      int x;
      cin >> x;
      a[x]++;
    }

    sort(a.rbegin(), a.rend());

    int cnt = a[0];
    int prev = a[0];

    for (int i{1}; i <= n; i++) {
      if (prev == 0) break;

      if (a[i] >= prev) {
        prev--;
      } else {
        prev = a[i];
      }

      cnt += prev;
    }

    cout << cnt << endl;
  }
}