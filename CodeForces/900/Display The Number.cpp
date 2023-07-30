#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    if (n % 2 == 1) {
      cout << "7";
      n -= 3;
    }

    for (int i{}; i < n / 2; i++) {
      cout << "1";
    }

    cout << endl;
  }
}