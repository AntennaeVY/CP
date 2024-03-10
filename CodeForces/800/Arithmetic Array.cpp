#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  
  while (T--) {
    int n;
    cin >> n;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      sum += val;
    }
    
    if (sum < n) {
      cout << 1 << endl;
    } else if (sum == n) {
      cout << 0 << endl;
    } else {
      cout << sum - n << endl;
    }
    
  }
}
