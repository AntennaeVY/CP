#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    
    int x = 2;

    if (n % 2) {
      cout << "3 1 2 ";
      x = 5;
    }
    
    for (int i = x; i <= n; i += 2) {
      cout << i << ' ' << i - 1 << ' ';
    }
    
    cout << endl;
  }
}