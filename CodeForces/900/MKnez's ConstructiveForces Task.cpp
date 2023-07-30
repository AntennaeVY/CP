#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int t = 1;
  cin >> t;
 
  while (t--) {
    int n;
    cin >> n;
    
    if (n == 3) {
    	cout << "NO" << endl;
    	continue;
    }
    
    cout << "YES" << endl;
    
    for(int i=0; i < n; i++) {
    	if (i % 2 == 0) 
    		cout << (n%2 == 0 ? 1 : (1 - n/2)) << " ";
    	else 
    		cout << (n%2 == 0 ? -1 : n/2) << " ";
    }
    
    cout << endl;
  }
}