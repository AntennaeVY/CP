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
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		map<int, vector<pair<int,int>>> m;
		
		int x=0, y=0;
		while(y < n) {
			while(y < n && b[y] == b[x])
				y++;
			
			m[b[x]].push_back({x, y-1});
			x = y;
		}
		
		vector<bool> painted(n);
		
		bool can = true;
		
		for(auto &[k, v] : m) {
			for(auto &[l, r] : v) {
				int L = l, R = r;
				
				while(L >= 0 && !painted[L] && a[L] <= k)
					L--;
				L++;
				
				while(R < n && !painted[R] && a[R] <= k)
					R++;
				R--;
				
				int mx = -1;
				
				for(int i=L; i <= R; i++) {
					mx = max(mx, a[i]);
					
					if (i >= l && i <= r)
						painted[i] = true;
				}
				
				can &= (mx == k);
			}
		}
		
		for(int i=0; i < n; i++)
			can &= (painted[i]);
		
		cout << (can ? "YES" : "NO") << endl;
	}
}