#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		
		vector<int> k;
		
		for(int i=1; i*i <= n; i++) {
			if (n % i)
				continue;
				
			k.push_back(i);
			
			if (i != 1 && n/i != i)
				k.push_back(n/i);
		}
		
		int ans = 1;
		
		for(auto x : k) {
			bool can = true;
			int gcd = -1;
			
			for(int i=0; i < x; i++) {
				
				int ones = (a[i] == 1);
				
				for(int j=i+x; j < n; j+=x) {
					ones += (a[j] == 1);
					
					if (gcd == -1)
						gcd = abs(a[i] - a[j]);
					else
						gcd = __gcd(gcd, abs(a[i] - a[j]));
				}
				
				// cout << x << " " << gcd << endl;
				
				can &= (gcd != 1 || ones == n/x);
			}
			
			ans += can;
		}
		
		cout << ans << endl;
	}
}