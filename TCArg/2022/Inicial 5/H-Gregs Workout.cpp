#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> ex(3, 0);
  int indx = 0, mx = 0;

  for (int i{}; i < n; i++) {
    int x;
    cin >> x;
    ex[i % 3] += x;

    if (ex[i % 3] > mx) {
      indx = i % 3;
      mx = ex[i % 3];
    }
  }

  switch (indx) {
    case 0:
      cout << "chest" << endl;
      break;
    case 1:
      cout << "biceps" << endl;
      break;
    case 2:
      cout << "back" << endl;
      break;
  }
}