#include <bits/stdc++.h>
using namespace std;

int main() {
  while (true) {
    double f, sum = 0;
    cin >> f;

    if (f == 0.00) break;

    int i;

    for (i = 1; sum < f; i++) {
      sum += 1 / (double)(i + 1);
    }

    cout << i - 1 << " card(s)" << endl;
  }
}