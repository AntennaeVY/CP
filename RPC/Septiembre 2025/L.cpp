#include<bits/stdc++.h>
using namespace std;

using ld = long double;
constexpr ld EPS = 1e-4;

ld calc_dist(int x1, int y1, int x2, int y2) {
	return sqrt(pow(y2-y1, 2) + pow(x2-x1, 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k, m;
	cin >> n >> k >> m;
	
	vector<int> x(n), y(n);
	for(int i=0; i < n; i++)
		cin >> x[i] >> y[i];
		
	vector<int> a(k), b(k), c(k);
	for(int i=0; i < k; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
	}
	map<int, vector<pair<int, ld>>> g;
	
	int ans = 1e9 + 5;
	
	for(int i=0; i <= (1 << (k+1)) - 1; i++) {
		int cost = 0;
		vector<vector<ld>> d(n, vector<ld>(n, 1e9+5));
		
		for(int u=0; u < n; u++) {
			d[u][u] = 0;
			
			int x1 = x[u], y1 = y[u];
			int x2 = x[(u+1) % n], y2 = y[(u+1) % n];
			
			ld dist = calc_dist(x1, y1, x2, y2);
			
			d[u][(u+1) % n] = d[(u+1) % n][u] = dist;
		}
		
		for(int j=0; j < k; j++) {
			if (((i >> j) & 1) == 0)
				continue;
				
			int u = a[j], v = b[j];
			cost += c[j];
			
			ld dist = calc_dist(x[u], y[u], x[v], y[v]);
			
			d[u][v] = min(d[u][v], dist);
			d[v][u] = min(d[v][u], dist);
		}
		
		for(int r=0; r < n; r++) {
			for(int p=0; p < n; p++) {
				for(int q=0; q < n; q++) {
					if (d[p][r] + d[r][q] < d[p][q] - EPS)
						d[p][q] = d[p][r] + d[r][q];
				}
			}
		}
		
		bool ok = true;
		
		for(int u=0; u < n; u++) {
			for(int v=0; v < n; v++) {
				ok &= (d[u][v] <= m + EPS);
			}
		}
		
		if (ok)
			ans = min(ans, cost);
	}
	
	cout << ans << "\n";
}