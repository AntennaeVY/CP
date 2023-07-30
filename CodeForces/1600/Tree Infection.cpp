#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int, int> m;
		vector<int> p;
		
		for(int i=2; i <= n; i++) {
			int u;
			cin >> u;
			
			m[u]++;
		}
		
		for(auto &[u, c] : m)
			p.push_back(c);
			
		n = p.size();	
		sort(p.rbegin(), p.rend());
		
		int ans = n;
		for(int i=0; i < n; i++) {
			p[i] = max(0, p[i] - (n-i));
		}
		
		bool inject = true;
		while(inject) {
			inject = false;
			
			sort(p.rbegin(), p.rend());
			
			if (p[0] == 0) {
				ans++;
				break;
			}
			
			for(int i=0; i < n; i++) {
				if (p[i] == 0)
					break;
				
				if (!inject && p[i] >= 2) {
					inject = true;
					p[i]--;
				}
				
				p[i]--;
			}
			
			ans++;
		}
		
		cout << ans << endl;
	}
}