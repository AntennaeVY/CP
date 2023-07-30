#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    deque<int> d;
    for (int i{}; i < n; i++) {
      int x;
      cin >> x;

      if (d.empty() || d.back() < x || d.front() < x)
        d.push_back(x);
      else
        d.push_front(x);
    }

    for (auto i : d) cout << i << " ";

    cout << endl;
  }
}