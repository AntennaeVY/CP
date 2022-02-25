#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n);

    for (int i{}; i < n; i++) {
      cin >> p[i];
    }

    int start = -1, end = 0;

    for (int i{}; i < n; i++) {
      if (p[i] != i + 1 && start == -1) {
        start = i;
      }

      if (p[i] == start + 1) {
        end = i;
        break;
      }
    }

    if (n != 1 && start != -1) {
      reverse(p.begin() + start, p.begin() + end + 1);
    }

    for (auto x : p) {
      cout << x << " ";
    }

    cout << endl;
  }
}