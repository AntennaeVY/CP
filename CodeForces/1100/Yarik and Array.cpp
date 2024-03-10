#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int ans = a[0], local_max = a[0];
		
		for(int i=1; i < n; i++) {
			if (local_max + a[i] < a[i] || (a[i-1] & 1) == (a[i] & 1))
				local_max = 0;
				
			local_max += a[i];
			
			ans = max(ans, local_max);
		}
		
		cout << ans << endl;
	}
}