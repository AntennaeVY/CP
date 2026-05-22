#include<bits/stdc++.h>
using namespace std;

class DSU {
private:
	vector<int> parent;
	vector<int> size;

public:
	DSU(int n) : parent(n,-1), size(n,1) {}
	
	int find(int x) {
		if (parent[x] == -1)
			return x;
			
		return parent[x] = find(parent[x]);
	}
	
	void join(int x, int y) {
		x = find(x), y = find(y);
		
		if (size[x] < size[y])
			swap(x, y);

		parent[y] = x;
		size[x] += size[y];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, r;
	cin >> n >> m >> r;
	
	vector<tuple<int,int,int>> edges;
	for(int i=0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		
		u--, v--;
		
		edges.push_back({0, u, v});
	}
	
	for(int i=0; i < r; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		u--, v--;
		
		edges.push_back({c, u, v});
	}
	
	DSU dsu(n);
	sort(edges.begin(), edges.end());
	
	long long ans = 0;
	
	for(int i=0; i < m+r; i++) {
		auto [c, u, v] = edges[i];
		
		if (dsu.find(u) == dsu.find(v))
			continue;
		
		ans += c;
		dsu.join(u, v);
	}
	
	cout << ans << "\n";
}