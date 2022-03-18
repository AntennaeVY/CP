#include <iostream>
using namespace std;

int main() {
  char c;
  int r;

  cin >> c >> r;

  int m = 8;

  if (c == 'a' || c == 'h') {
    m -= 3;
  }

  if (r == 1 || r == 8) {
    m -= 3;
  }

  if ((r == 1 || r == 8) && (c == 'a' || c == 'h')) {
    m += 1;
  }

  cout << m;
}