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
		
		vector<int> b(n);
		for(auto &bi : b) cin >> bi;
		
		map<int,int> m;
		for(int i=0; i < n; i++)
			m[b[i]]++;
			
		bool can = true;
			
		for(auto [k, v] : m)
			can &= (v % k == 0);
			
		if (!can) {
			cout << -1 << "\n";
			continue;
		}
		
		map<int,vector<int>> p;
		
		for(int i=0; i < n; i++) {
			p[b[i]].push_back(i);
		}
		
		int c = 1;
		vector<int> ans(n);
		
		for(auto &[k, v] : p) {
			for(int i=0; i <= v.size() / k; i++) {
				for(int j=0; j < k; j++) {
					if (i*k + j >= v.size())
						break;
					
					int x = v[i*k + j];
					ans[x] = c;
				}
				
				c++;
			}
		}
		
		for(int i=0; i < n; i++)
			cout << ans[i] << " ";
			
		cout << "\n";
	}
}