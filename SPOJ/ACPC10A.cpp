#include <bits/stdc++.h>
using namespace std;

int main() {
  while (true) {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    if (a1 == a2 && a2 == a3) break;

    if (a1 != 0 && a2 % a1 == 0 && a2 / a1 * a2 == a3)
      cout << "GP " << a2 / a1 * a3 << endl;
    else
      cout << "AP " << a2 - a1 + a3 << endl;
  }
}