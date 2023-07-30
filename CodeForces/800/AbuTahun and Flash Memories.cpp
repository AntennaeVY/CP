#include <iostream>
using namespace std;

int main() {
  int n, x, a;
  cin >> n >> x >> a;

  cout << n / (a / x) + !(n % (a / x) == 0 && n % (a / x) != n);
}