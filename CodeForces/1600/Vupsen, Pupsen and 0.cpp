#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	a = abs(a), b = abs(b);
	
	if (a < b)
		swap(a,b);
		
	if (b == 0)
		return a;
		
	return gcd(b, a % b);
}

long long lcm(int a, int b) {
	return a*b / gcd(a, b);
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n, 0), idx(n);
		for(int i=0; i < n; i++) {
			cin >> a[i];
			idx[i] = i;
		}
		
		sort(idx.begin(), idx.end(), [&](int i, int j){
			return abs(a[i]) > abs(a[j]);
		});
		
		sort(a.begin(), a.end(), [](int x, int y){
			return abs(x) > abs(y);
		});
		
		for(int i=0; i < n; i++) {
			int sign = abs(a[i])/a[i];
			
			if (i % 2) {
				b[idx[i]] = lcm(a[i-1], a[i]) / abs(a[i]);
			} else if (i != n-1){
				int sign2 = abs(a[i+1])/a[i+1];
				b[idx[i]] = -1 * (sign2 / sign) * lcm(a[i], a[i+1]) / abs(a[i]);
			}
		}
		
		if (n % 2) {
			long long amt = lcm(lcm(a[n-3], a[n-2]), a[n-1]); 
		
			b[idx[n-3]] = abs(a[n-3])/a[n-3] * amt/abs(a[n-3]);
			b[idx[n-2]] = abs(a[n-2])/a[n-2] * amt/abs(a[n-2]);
			b[idx[n-1]] = -2LL*abs(a[n-1])/a[n-1] * amt/abs(a[n-1]);
		}
		
		for(auto &bi : b)
			cout << bi << " ";
			
		cout << endl;
		
		// long long ans = 0;
		// for(int i=0; i < n; i++) {
			// ans += a[i]*b[i];
		// }
		// cout << ans << endl;
	}
}