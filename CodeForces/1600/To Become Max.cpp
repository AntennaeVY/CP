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
		
		int l=*max_element(a.begin(), a.end()), r = l + n + 1;
		while(l+1 < r) {
			int x = l + (r-l)/2;
			bool can = false;
			
			int j=0;
			long long sum = 0;
			for(int i=0; i < n; i++) {
				while(j < n) {
					if (a[j] >= x - j + i) {
						long long target = 1LL * x * (j-i) - 1LL * (j-i) * (j-i-1) / 2;
						
						if (target - sum <= k) {
							can = true;
						}
							
						break;
					}
					
					sum += a[j++];
				}
				
				sum -= a[i];
			}
			
			if (can)
				l = x;
			else
				r = x;
		}
		
		
		cout << l << "\n";
	}
}