#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> k(n);
		for(auto &ki:k) cin >> ki;
		
		vector<int> c(m);
		for(auto &ci:c) cin >> ci;
		
		sort(k.rbegin(), k.rend());
		
		int j = 0;
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			if (j+1 <= k[i])
				ans += c[j++];
			else
				ans += c[k[i]-1];
		}
		
		cout << ans << endl;
	}
}