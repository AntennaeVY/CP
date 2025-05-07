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
		
		vector<int> p(n);
		vector<bool> vis(n+1);
		
		for(int i=0; i < n; i++) {
			p[i] = ((i+1) + i) % n;
			
			if (p[i] == 0)
				p[i] = n;
			
			vis[p[i]] = true;
		}
		
		bool can = true;
		for(int i=1; i <= n; i++) {
			can &= vis[i];
		}
			
		if (!can) {
			cout << -1 << endl;
			continue;
		}
		
		for(auto &pi : p)
			cout << pi << " ";
		cout << endl;
	}
}