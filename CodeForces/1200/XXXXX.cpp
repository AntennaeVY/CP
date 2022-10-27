#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;	
		
		int ans = -1;
		long long sum = 0;
		
		for(int i=0; i < n; i++) {
			sum += a[i];
			
			if (sum%x != 0)
				ans = max(ans, i+1);
		}
		
		for(int i=0; i < n; i++) {
			sum -= a[i];
			
			if (sum%x != 0)
				ans = max(ans, n-i-1);
		}
		
		cout << ans << endl;
	}
}