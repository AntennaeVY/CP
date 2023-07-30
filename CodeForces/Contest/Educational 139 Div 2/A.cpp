#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    
    int ans = 0;

    for (int i = 1; i <= 9; i++) {
    	int d = i;
    	
    	while(d <= n) {
    		ans++;
    		d *= 10;
    	}
    }
    
    cout << ans << endl;
  }
}