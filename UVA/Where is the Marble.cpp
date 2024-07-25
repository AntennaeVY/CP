#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 1; i <= 67; i++) {
    int n, q;
    cin >> n >> q;

    if (n == 0 && q == 0) break;
    
    cout << "CASE# " << i << ":\n";

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;

	sort(a.begin(), a.end());

    while (q--) {
      int x; 
      cin >> x;
      
      
      int l = -1, r = n-1;
      while(l+1 < r) {
      	int m = l + (r-l)/2;
      	
      	if (a[m] >= x) 
      		r = m;
      	else
      		l = m;
      }
      
      cout << x << " ";

      if (a[r] != x) 
      	cout << "not found" << "\n";
      else
      	cout << "found at " << r + 1 << "\n"; 
    }
  }
}