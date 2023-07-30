#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int last=2;
		map<int, int> mx, mn, mx_suf, mn_suf;
		mx[1] = 1, mx_suf[1] = 1;
		
		while(n--) {
			char s;
			cin >> s;
			
			int u, v;
			cin >> u >> v;
			
			if (s == '+') {	
				mn_suf[last] = min(0, mn_suf[u] + v);
				mx_suf[last] = max(0, mx_suf[u] + v);   
				
				mn[last] = min(mn_suf[last], mn[u]);
				mx[last] = max(mx_suf[last], mx[u]);
				
				last++;
			} else {
				int k;
				cin >> k;
			
				cout << (k >= mn[v] && k <= mx[v] ? "YES" : "NO") << endl;
			}		
		}
	}
}