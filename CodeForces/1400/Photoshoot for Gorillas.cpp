#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		
		int w;
		cin >> w;
		
		vector<int> a(w);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		vector<vector<ll>> grid(n+1, vector<ll>(m+1));
		for(int i=0; i <= n-k; i++) {
			for(int j=0; j <= m-k; j++) {
				grid[i][j] += 1;
				
				grid[i][j+k] += -1;
				grid[i+k][j] += -1;
				grid[i+k][j+k] += 1;
			}
		}

		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				grid[i+1][j] += grid[i][j];
			}
		}
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				grid[i][j+1] += grid[i][j];
			}
		}
		
		map<int, ll> mp;
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				mp[-grid[i][j]]++;
			}
		}
		
		int x=0;
		ll ans = 0;
		
		for(auto &[c, cnt] : mp) {
			ll sum = 0;
			
			for(int i=0; i < cnt; i++) {
				if (x+i >= w)
					break;
					
				sum += a[x+i];
			}
		
			ans += sum * -c;
			x += cnt;
		}
		
		cout << ans << endl;
	}
}