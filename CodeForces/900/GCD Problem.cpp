#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    if (n % 2 == 0)
      printf("%d %d %d\n", n - 3, 2, 1);
    else if (n % 4 == 1)
      printf("%d %d %d\n", n / 2 - 1, n / 2 + 1, 1);
    else
      printf("%d %d %d\n", n / 2 - 2, n / 2 + 2, 1);
  }
}