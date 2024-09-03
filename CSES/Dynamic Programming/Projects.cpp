#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n), b(n), p(n);
	for(int i=0; i < n; i++)
		cin >> a[i] >> b[i] >> p[i];
		
	vector<int> z(n);
	iota(z.begin(), z.end(), 0);
	
	sort(z.begin(), z.end(), [&](const int &i, const int &j){
		if (b[i] == b[j])
			if (a[i] == a[j])
				return p[i] >= p[j];
			else
				return a[i] <= a[j];
			
		return b[i] < b[j];
	});
	
	vector<long long> dp(n+1, 0);
	set<pair<int,int>> s;
	s.insert({0, 0});
	
	for(int i=1; i <= n; i++) {
		int j = z[i-1];
		
		int k = prev(s.upper_bound({a[j], 0}))->second;
			
		long long take = p[j] + dp[k];
		
		dp[i] = max(dp[i-1], take);
		s.insert({b[j], i});
	}
	
	cout << dp[n] << endl;
}