#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int l, r;
    cin >> l >> r;

    int x = l;
    int y = l * 2;

    cout << x << " " << y << endl;
  }
}