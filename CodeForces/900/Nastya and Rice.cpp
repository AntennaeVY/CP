#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    int left = (a - b) * n;
    int right = (a + b) * n;

    if (left > c + d || right < c - d) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
}