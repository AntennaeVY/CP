#include <iostream>
using namespace std;

int main() {
  int k, n;
  cin >> k;

  n = (k - 1) / 3;
  int s_m3 = 3 * (n * (n + 1) / 2);

  n = (k - 1) / 5;
  int s_m5 = 5 * (n * (n + 1) / 2);

  n = (k - 1) / 15;
  int s_m3n5 = 15 * (n * (n + 1) / 2);

  cout << s_m3 + s_m5 - s_m3n5;
}