#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    cout << (int)pow(2, floor(log2(n))) - 1 << endl;
  }
}