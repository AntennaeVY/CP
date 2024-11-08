#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    
    // f(t) = 2^m - 1;
    // g(t) = (2^n - 2^m)
    
    // |2^m - 1 - 2^n + 2^m|
    // |2^(m+1) - 2^n - 1 |
    
    cout << 1;
    for(int i=0; i < n-1; i++) {
    	cout << 0;
    }
    
    cout << endl;

  }
}