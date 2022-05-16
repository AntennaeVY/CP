#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;

  while (cin >> s) {
    bool hasUnderscores = false;
    bool invalid = false;

    if (s[0] == '_' || isupper(s[0])) {
      cout << "Error!" << endl;
      continue;
    }

    if (s.size() == 1) {
      cout << s << endl;
      continue;
    }

    for (int i{}; i < s.size() - 1; i++) {
      if ((s[i] == '_' && isupper(s[i + 1])) ||
          (s[i] == '_' && s[i + 1] == '_') || (s.back() == '_') ||
          (hasUnderscores && isupper(s[i]))) {
        cout << "Error!" << endl;
        invalid = true;
        break;
      }

      if (s[i] == '_') hasUnderscores = true;
    }

    if (invalid) continue;

    for (int i{}; i < s.size(); i++) {
      if (s[i] == '_') {
        cout << (char)toupper(s[++i]);
        continue;
      }

      if (isupper(s[i])) {
        cout << "_" << (char)tolower(s[i]);
        continue;
      }

      cout << s[i];
    }

    cout << endl;
  }
}