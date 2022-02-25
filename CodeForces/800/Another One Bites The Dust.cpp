#include <iostream>
using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;

  cout << 2 * c + (abs(a - b) >= 2 ? (a < b ? a * 2 + 1 : b * 2 + 1) : a + b);
}