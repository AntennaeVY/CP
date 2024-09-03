#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n), d(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		for(auto &di : d) cin >> di;
		
		vector<int> m(n+1, -1);
		for(int i=0; i < n; i++) {
			m[a[i]] = b[i];
		}
		
		int k = 0;
		vector<int> ci(n+1, -1);
		
		for(int i=0; i < n; i++) {
			int x = a[i]; 
			
			if (ci[x] != -1)
				continue;
			
			while(ci[x] == -1) {
				ci[x] = k;
				x = m[x];
			}
			
			
			k++;
		}
		
		vector<int> p(k, -1);
		for(int i=0; i < n; i++) {
			if (d[i] != 0)
				p[ci[d[i]]] = 1;
			else if (d[i] == 0 && p[ci[a[i]]] == -1)
				p[ci[a[i]]] = (a[i] == b[i] ? 1 : 2);
		}
		
		int ans = 1;
		
		for(auto &pi : p)
			ans *= pi, ans %= MOD;
			
		cout << ans << endl;
	}
}