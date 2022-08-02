#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;

  for (int i = (n.size() - 1); i >= 0; i--) {
    int num = (int)(n[i]) - 48;

    if (num >= 5) {
      cout << "-O";
      num -= 5;
    } else
      cout << "O-";

    cout << "|";

    for (int j{}; j < num; j++) {
      cout << "O";
    }

    cout << "-";

    for (int j{}; j < (4 - num); j++) {
      cout << "O";
    }

    cout << endl;
  }
}