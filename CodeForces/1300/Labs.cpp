#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<long long>> v(n, vector<long long>(n));

  for (int i{}; i < n; i++) {
    for (int j{}; j < n; j++) {
      if (i % 2) {
        v[j][i] = (i + 1) * n - j;
      } else {
        v[j][i] = (i * n) + (j + 1);
      }
    }
  }

  for (auto x : v) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
}