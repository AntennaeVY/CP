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
		
		int sum = 0;
		for(int i=1; i < n; i++) {
			sum += abs(a[i] - a[i-1]);
		}
		
		int ans = sum;
		for(int i=0; i < n; i++) {
			int nsum = sum;
			
			if (i-1 >= 0)
				nsum -= abs(a[i] - a[i-1]);
				
			if (i+1 < n)
				nsum -= abs(a[i+1] - a[i]);
			
			if (i-1 >= 0 && i+1 < n)
				nsum += abs(a[i+1] - a[i-1]);	
			
			ans = min(ans, nsum);
		}
		
		cout << ans << '\n';
	}
}