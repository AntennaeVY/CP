#include <bits/stdc++.h>
using namespace std;

constexpr long double EPS = 1e-9;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;

    sort(a.begin(), a.end());

    long double sum = accumulate(a.begin(), a.end(), 0LL);
    
    long long l = -1, r = 1e18;
    while (l + 1 < r) {
      long long m = l + (r - l) / 2;
		
	  long double d = (sum + m) / (2 * n);
	  
	  // cout << m << " " <<  d << endl;

	  
	  int cnt = 0;
	  for(int i=0; i < n-1; i++) 
	  	cnt += (a[i] < d);
	
	
	  
	  if (cnt > (n * 1.0)/2)
	  	r = m;
      else
      	l = m;
    }
    
    if (r == 1e18)
    	cout << -1 << endl;
    else
    	cout << r << endl;
  }
}