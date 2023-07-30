#include <iostream>
#include <map>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    long long cnt = 0;

    map<int, int> m;

    for (int i{}; i < n; i++) {
      int x;
      cin >> x;

      x -= i;

      cnt += m[x];

      m[x]++;
    }

    cout << cnt << endl;
  }
}