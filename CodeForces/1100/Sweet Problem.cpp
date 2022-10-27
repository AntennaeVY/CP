#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    vector<int> c(3);
    for(auto &it:c) cin >> it;
    
    sort(c.rbegin(), c.rend());
    int r = c[0], g = c[1], b = c[2];
    
    if (r >= g+b)
    	cout << g+b << endl;
    else
    	cout << (r+g+b)/2 << endl;
  }
}