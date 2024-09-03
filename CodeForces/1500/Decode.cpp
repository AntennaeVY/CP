#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int n = s.size();
		
		vector<int> p(n+1);
		for(int i=0; i < n; i++) {
			if (s[i] == '0')
				p[i+1] = p[i] + 1;
			else
				p[i+1] = p[i] - 1;
		}
		
		map<int, vector<int>> m;
		
		for(int i=0; i <= n; i++) {
			m[p[i]].push_back(i);
		}
		
		long long ans = 0;
		
		for(auto &[c, v] : m) {
			long long sum = 0;
		
			
			for(int i=0; i < v.size(); i++) {
				sum += v[i];
			}
			
			for(int i=0; i < v.size(); i++) {
				sum -= v[i];
				
				long long x = v[i];
				long long k = v.size() - i - 1;
				
				ans += 1LL * (x+1) * (n*k + k - sum);
				ans %= mod;
			}
		}
		
		cout << ans << endl;
	}
}