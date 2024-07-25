#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;
    
    long long L = (k + 1) / 2, R = k / 2;
    
    int l = 0, r = n-1;

	while(l <= r && (L > 0 || R > 0)) {
		if (L > 0) {
			int cnt = min(1LL * a[l], L);
			
			a[l] -= cnt, L -= cnt;
			
			l += a[l] == 0;
		}
			
		if (R > 0) {
			int cnt = min(1LL * a[r], R);
			
			a[r] -= cnt, R -= cnt; 
			
			r -= a[r] == 0;
		}
	}
	
	if (l > r)
		cout << n << endl;
	else
		cout << l + n - r - 1 << endl;
  }
}