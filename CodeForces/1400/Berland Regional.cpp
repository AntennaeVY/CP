#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> v(n), s(n);
		for(auto &vi : v) cin >> vi;
		for(auto &si : s) cin >> si;
		
		map<int, vector<long long>> m, p;
		
		for(int i=0; i < n; i++) {
			m[v[i]].push_back(s[i]);
		}
		
		for(auto &[u, S] : m) {
			sort(S.begin(), S.end());
			
			p[u].assign(S.size() + 1, 0LL);
			
			
			for(int i=0; i < S.size(); i++) {
				p[u][i+1] = p[u][i] + S[i];
			}
		}
		
		vector<long long> ans(n+1, 0);
		
		for(auto &[u, S] : m) {
			for(int i=1; i <= S.size(); i++) {
				int r = S.size() % i;
				
				ans[i] += p[u][S.size()] - p[u][r];
			}
		}
		
		for(int i=1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		
		cout << endl;
	}
}