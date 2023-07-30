#include <math.h>

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int n;
  cin >> n;

  unordered_set<int> s;
  int mx = 0;
  int cnt = 0;

  for (int i{}; i < 2 * n; i++) {
    int x;
    cin >> x;

    if (s.count(x)) {
      cnt--;
      s.erase(x);
    } else {
      cnt++;
      s.insert(x);
    }

    mx = max(mx, cnt);
  }

  cout << mx;
}