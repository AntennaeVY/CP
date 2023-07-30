#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    char c;
    cin >> s >> c;

    bool cmp = false;

    for (size_t i{}; i < s.size(); i++) {
      if (i % 2 == 0 && s[i] == c) {
        cmp = true;
      }
    }

    if (cmp) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}