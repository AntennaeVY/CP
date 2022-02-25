#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);

  for (int i{}; i < n; i++) {
    cin >> a[i];
  }

  for (int i{}; i < n; i++) {
    cin >> b[i];
  }

  int ac = 0, bc = 0, ab = 0;

  for (int i{}; i < n; i++) {
    if (a[i] == 1 && b[i] == 0) {
      ac++;
    } else if (a[i] == 0 && b[i] == 1) {
      bc++;
    } else {
      ab++;
    }
  }

  if (ac == 0) {
    cout << -1;
  } else {
    cout << (ac > bc ? 1 : bc / ac + 1);
  }
}