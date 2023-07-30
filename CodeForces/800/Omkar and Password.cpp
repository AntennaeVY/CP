#include <math.h>

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i{}; i < n; i++) {
      cin >> v[i];
    }

    bool eq = true;

    for (int i{}; i < n - 1; i++) {
      eq &= v[i] == v[i + 1];
    }

    cout << (eq ? n : 1) << endl;
  }
}