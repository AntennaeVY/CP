#include <bits/stdc++.h>
using namespace std;

int main() {
  while (1) {
    int n;
    cin >> n;

    if (n == 0) break;

    vector<int> a(n);

    for (int i{}; i < n; i++) {
      cin >> a[i];
    }

    bool ambiguous = true;

    for (int i{}; i < n; i++) {
      if (a[a[i] - 1] != i + 1) {
        ambiguous = false;
        break;
      }
    }

    if (ambiguous)
      cout << "ambiguous" << endl;
    else
      cout << "not ambiguous" << endl;
  }
}