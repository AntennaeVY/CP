#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  cout << n / 2 << endl;

  for (int i{}; i < n / 2 - (n % 2); i++) cout << 2 << " ";

  if (n % 2) cout << 3;

  return 0;
}