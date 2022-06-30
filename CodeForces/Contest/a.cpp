#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int h2 = n / 3, h1 = n / 3, h3 = n / 3;

    int r = n % 3;

    if (r == 0) {
      h1 += 1;
      h3 -= 1;
    } else if (r == 1) {
      h1 += r + 1;
      h3 -= 1;
    } else {
      h1 += r;
      h2 += 1;
      h3 -= 1;
    }

    cout << h2 << " " << h1 << " " << h3 << endl;
  }
}