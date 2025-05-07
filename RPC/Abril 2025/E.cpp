#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	
	map<int, vector<int>> g;
	
	for(int i=0; i < n-3; i++) {
		int x, y;
		cin >> x >> y;
		
		x--, y--;
		
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	int c = 0;
	vector<int> comp(n, -1);
	map<int, pair<int,int>> ec;
	map<int, map<int, int>> dist;
	
	vector<vector<vector<int>>> dist_end(3, vector<vector<int>>(2, vector<int>(n, -1)));
	
	auto dfs1 = [&](auto &&self, int u, int i = 0, int p = -1) -> pair<int,int> {
		comp[u] = c;
		
		int x = u, mx = i;
		
		for(auto &v : g[u]) {
			if (v == p)
				continue;
				
			auto [y, my] = self(self, v, i+1, u);
			
			if (my > mx)
				x = y, mx = my;
		}
			
		return {x, mx};
	};
	
	vector<int> mxs(3, 0);
	
	auto dfs2 = [&](auto &&self, int x, int u, int i = 0, int p = -1) -> void{
		dist_end[c][x][u] = i;
		mxs[c] = max(mxs[c], i);
		
		for(auto &v : g[u])
			if (v != p)
				self(self, x, v, i+1, u);
	};

	
	for(int i=0; i < n; i++) {
		if (comp[i] != -1)
			continue;
			
		auto [x, _] = dfs1(dfs1, i);
		auto [y, __] = dfs1(dfs1, x);
		
		ec[c] = {x, y};
		
		dfs2(dfs2, 0, x);
		dfs2(dfs2, 1, y);
		
		c++;
	}
	
	while(q--) {
		int a, b;
		cin >> a >> b;
		
		a--, b--;
		
		int ca = comp[a];
		int cb = comp[b];
		
		if (ca > cb) {
			swap(ca, cb);
			swap(a, b);
		}
			
		int dx, dy, dz;
		
		dx = max(dist_end[ca][0][a], dist_end[ca][1][a]);
		dy = max(dist_end[cb][0][b], dist_end[cb][1][b]);

		for(int i=0; i < 3; i++) {
			if (i != ca && i != cb)
				dz = mxs[i];
		}
		
		cout << dx + dy + dz + 3 << "\n";
	}
}