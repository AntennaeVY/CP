#include <iostream>
using namespace std;

int main() {
  string s, a;
  cin >> s >> a;

  if (s.size() < a.size()) {
    cout << "No" << endl;
    return 0;
  }

  bool found;

  for (int i{}; i < s.size(); i++) {
    found = true;
    for (int j{}; j < a.size(); j++) {
      if (a[j] != s[i + j]) {
        found = false;
        break;
      }
    }

    if (found) break;
  }

  if (!found) {
    for (int i = s.size() - 1; i >= 0; i--) {
      found = true;
      for (int j{}; j < a.size(); j++) {
        if (a[j] != s[i - j]) {
          found = false;
          break;
        }
      }

      if (found) break;
    }
  }

  if (found)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}