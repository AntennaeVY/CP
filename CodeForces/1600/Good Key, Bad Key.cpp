#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<long long> p(n+1), q(n+1);
		
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + (a[i] - k); 
		}
		
		for(int i=0; i < n; i++) {
			long long sum = 0;
			
			for(int j=0, x=1; j < 32; j++, x++) {
				if (n-1-i+j < n)
					sum += (a[n-1-i+j] >> min(x, 31));
				else
					break;
			}
			
			q[i+1] = sum; 
		}
		
		long long ans = -1e18;
		
		for(int i=0; i <= n; i++) {
			ans = max(ans, p[i] + q[n-i]);
		}
		
		cout << ans << endl;
	}
}