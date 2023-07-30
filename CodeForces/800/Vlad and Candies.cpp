#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> m(n);

    for (int i{}; i < n; i++) {
      int a;
      cin >> a;

      m[i] = a;
    }

    sort(m.rbegin(), m.rend());

    if (m.size() == 1 && m[0] > 1) {
      cout << "NO" << endl;
    } else if (m[0] - m[1] > 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}