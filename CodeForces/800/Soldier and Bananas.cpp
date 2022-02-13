#include <iostream>
using namespace std;

int main() {
  int k, n, w;
  cin >> k >> n >> w;

  int total = k * w * (w + 1) / 2;
  int needed = total - n;

  if (needed > 0) {
    cout << needed;
  } else {
    cout << 0;
  }
}