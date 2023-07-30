#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n;

    string t;
    cin >> t;

    string r = "";

    for (int i = n - 1; i >= 0; i--) {
      if (t[i] == '0') {
        int num = stoi(t.substr(i - 2, 2));
        r += char(96 + num);
        i -= 2;
      } else {
        r += char(96 + t[i] - 48);
      }
    }

    reverse(r.begin(), r.end());
    cout << r << endl;
  }
}