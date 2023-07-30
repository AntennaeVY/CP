#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int, vector<int>> tree;
		for(int i=0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		
		map<int, int> leaves;
		map<int, bool> visited;
		
		function<int(int)> dfs;
		dfs = [&](int v) {
			visited[v] = true;
			
			int cnt = 0;
			for(auto &u : tree[v]) {
				if (visited[u])
					continue;
				
				cnt += dfs(u);		
			}
			
			if (tree[v].size() == 1 && v != 1)
				cnt += 1;
				
			leaves[v] = cnt;
			return cnt;
		};
		
		dfs(1);
		
		int q;
		cin >> q; 
		
		while(q--) {
			int x, y;
			cin >> x >> y;
			
			cout << 1LL * leaves[x] * leaves[y] << endl;
		}
	}
}