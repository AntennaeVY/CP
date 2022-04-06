#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    if (k <= sqrt(n) && k % 2 == n % 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}