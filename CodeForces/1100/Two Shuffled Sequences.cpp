#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> frq;
  int cnt{};

  for (int i{}; i < n; i++) {
    int x;
    cin >> x;

    frq[x] += 1;
  }

  for (auto x : frq) {
    if (x.second > 2) {
      cout << "NO" << endl;
      return 0;
    } else if (x.second == 2) {
      cnt++;
    }
  }

  cout << "YES" << endl << cnt << endl;
  n -= cnt;

  for (auto x : frq) {
    if (cnt && x.second == 2) {
      cout << x.first << " ";
      cnt--;
      x.second -= 1;
    } else if (!cnt) {
      break;
    }
  }

  cout << endl << n << endl;

  for (auto it = frq.rbegin(); it != frq.rend(); it++) {
    cout << it->first << " ";
  }
}