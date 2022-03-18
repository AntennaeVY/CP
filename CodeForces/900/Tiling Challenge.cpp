#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<char>> b;

  for (int i{}; i < n; i++) {
    vector<char> x;
    for (int j{}; j < n; j++) {
      char y;
      cin >> y;
      x.push_back(y);
    }
    b.push_back(x);
  }

  bool all = true;

  for (int i{}; i < n - 2; i++) {
    for (int j{1}; j < n - 1; j++) {
      if (b[i][j] == '.' && b[i + 1][j] == '.' && b[i + 2][j] == '.' &&
          b[i + 1][j - 1] == '.' && b[i + 1][j + 1] == '.') {
        b[i][j] = '#';
        b[i + 1][j] = '#';
        b[i + 2][j] = '#';
        b[i + 1][j - 1] = '#';
        b[i + 1][j + 1] = '#';
      }
    }
  }

  for (int i{}; i < n; i++) {
    for (int j{}; j < n; j++) {
      if (b[i][j] == '.') {
        all = false;
        break;
      }
    }
  }

  if (all) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}