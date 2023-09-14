#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> x(n);
		for(auto &xi : x) cin >> xi;
		
		vector<int> z(n);
		iota(z.begin(), z.end(), 0);
		
		sort(z.begin(), z.end(), [&](int i, int j){return x[i] < x[j];});
		
		vector<long long> prefix(n, 0), suffix(n, 0);
		
		prefix[0] = x[z[0]], suffix[n-1] = x[z[n-1]];
		
		for(int i=1; i < n; i++) {
			prefix[i] += prefix[i-1] + x[z[i]];
		}
		
		for(int i=n-2; i >= 0; i--) {
			suffix[i] += suffix[i+1] + x[z[i]];
		}
		
		vector<long long> ans(n, 0);
		
		for(int i=0; i < n; i++) {
			if (i < n-1)
				ans[z[i]] += suffix[i+1];
				
			ans[z[i]] -= prefix[i];
			ans[z[i]] += 2LL*x[z[i]]*(i+1) - 1LL*x[z[i]]*n + n;
		}
		
		for(auto &ansi : ans)
			cout << ansi << " ";
		
		cout << endl;
	}
}