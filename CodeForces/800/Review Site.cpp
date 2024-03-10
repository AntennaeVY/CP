#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    
    int cnt = 0;
    for (int i=0; i < n; i++) {
      int k;
      cin >> k;
      
      if (k != 2) ++cnt;
    }
    cout << cnt << '\n';
  }
}