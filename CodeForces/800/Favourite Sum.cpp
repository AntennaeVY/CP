#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;

    long long sum = 1LL * x * ((1LL * x) + 1) / 2;
    long long acc = 0;

    for (int i{}; i < n; i++) {
      int a;
      cin >> a;

      if (a <= x) acc -= a;
    }

    cout << sum + 2 * acc << endl;
  }
}