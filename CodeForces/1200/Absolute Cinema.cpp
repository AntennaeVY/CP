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
		
		vector<long long> f(n);
		for(auto &fi : f) cin >> fi;
		
		vector<int> ans(n, 0);
		
		for(int i=1; i < n-1; i++) {
			ans[i] = (f[i+1] - 2*f[i] + f[i-1]) / 2;
		}
		
		long long s0 = 0, sn = 0;
		for(int i=0; i < n; i++) {
			if (i > 0)
				sn += i * ans[i]; 
			
			if (i < n-1)
				s0 += (n-i-1) * ans[i];
				
		}
		
		ans[0] = (f[n-1] - s0) / (n-1);
		ans[n-1] = (f[0] - sn) / (n-1);
		
		for(auto &ansi : ans)
			cout << ansi << ' ';
		cout << '\n';
	}
}