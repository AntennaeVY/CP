#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<char, int> m;
  int cnt = 0;

  for (int i{}; i < n - 1; i++) {
    char k, d;
    cin >> k >> d;

    if (m.find(k) == m.end()) {
      m[k] = 1;
    } else {
      m.find(k)->second += 1;
    }

    if (m.find(tolower(d)) == m.end() || m.find(tolower(d))->second == 0) {
      cnt++;
    } else {
      m.find(tolower(d))->second -= 1;
    }
  }

  cout << cnt;
}