#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> m;

  for (int i{}; i < n; i++) {
    int x;
    cin >> x;

    m[x]++;
  }

  bool no = false;

  if (m.size() < 3) {
    cout << "-1";
  } else {
    int frq = min(min(m[1], m[2]), m[4]);
    m[1] -= frq;
    m[2] -= frq;
    m[4] -= frq;

    int frq2 = min(min(m[1], m[2]), m[6]);
    m[1] -= frq2;
    m[2] -= frq2;
    m[6] -= frq2;

    int frq3 = min(min(m[1], m[3]), m[6]);
    m[1] -= frq3;
    m[3] -= frq3;
    m[6] -= frq3;

    bool no = false;

    for (auto x : m) {
      if (x.second) {
        no = true;
      }
    }

    if (no) {
      cout << -1;
    } else {
      while (frq--) {
        cout << 1 << " " << 2 << " " << 4 << endl;
      }

      while (frq2--) {
        cout << 1 << " " << 2 << " " << 6 << endl;
      }

      while (frq3--) {
        cout << 1 << " " << 3 << " " << 6 << endl;
      }
    }
  }
}