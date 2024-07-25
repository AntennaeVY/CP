#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<int> d;

    for (int i = 1; i * i <= n; i++) {
      if (n % i) 
      	continue;

      d.push_back(i);

      if (i * i != n) 
      	d.push_back(n / i);
    }
    
    int ans = n;

    for (auto x : d) {
      bool can = true;
      int times = 0;

      for (int i = 0; i < x; i++) {
      	map<char, int> m;
        
        for (int j = i; j < n; j += x) {
        	m[str[j]]++;
        	
        	can &= (m.size() <= 2);
        	
        	if (!can)
        		goto next;
        }
        
        times += (m.size() == 2);
        
        if (m.size() == 2 && m.begin()->second != n/x - 1 && m.begin()->second != 1) {
        	can = false;
        	break;
        }
        
        if (times > 1) {
        	can = false;
        	break;
        }
      }
    
      next:
      	if (can)
      		ans = min(ans, x);
    }
    
    cout << ans << endl;
  }
}