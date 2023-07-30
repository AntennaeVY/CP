#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int j{}; j < n * 2; j++) {
    cout << " ";
  }

  cout << 0 << endl;

  for (int i = 1; i <= n; i++) {
    for (int j{}; j < (n - i) * 2; j++) {
      cout << " ";
    }

    for (int j{}; j <= i; j++) {
      cout << j << " ";
    }

    for (int j = (i - 1); j >= 1; j--) {
      cout << j << " ";
    }

    cout << 0 << endl;
  }

  for (int i = (n - 1); i >= 1; i--) {
    for (int j = (n - i) * 2; j > 0; j--) {
      cout << " ";
    }

    for (int j{}; j <= i; j++) {
      cout << j << " ";
    }

    for (int j = (i - 1); j >= 1; j--) {
      cout << j << " ";
    }

    cout << 0 << endl;
  }

  for (int j{}; j < n * 2; j++) {
    cout << " ";
  }

  cout << 0 << endl;
}