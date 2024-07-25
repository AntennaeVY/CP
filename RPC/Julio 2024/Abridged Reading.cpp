#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> p(n);
	for(auto &pi : p) cin >> pi;
	
	vector<vector<int>> graph(n);
	vector<int> in(n), out(n);
	
	for(int i=0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		
		u--, v--;
		
		graph[u].push_back(v);
		out[u]++, in[v]++;
	}

	int ans = 1e9;
	vector<int> mns;
	
	for(int i=0; i < n; i++) {
		if (in[i] != 0)
			continue;
		
		int t = 0, mn = 1e9;
		vector<int> tin(n), tout(n);
		vector<int> s(n);
		vector<int> leaves;
		vector<vector<int>> up(n, vector<int>(20));
	
		auto calc = [&](auto &&self, int u, int k = 0, int parent = -1) -> void {
			tin[u] = t++;
			k += p[u];
			
			up[u][0] = parent;
			
			for(int i=1; i < 20; i++) {
				if (up[u][i-1] == -1)
					break;
				
				up[u][i] = up[ up[u][i-1] ][i-1];
			}
			
			for(auto v : graph[u])
				self(self, v, k, u);
				
			s[u] = k;
			
			if (out[u] == 0) {
				mn = min(mn, k);
				leaves.push_back(u);
			}
			
			tout[u] = t;
		};
		
		auto is_ancestor = [&](int u, int v) -> bool {
			return tin[u] <= tin[v] && tout[u] >= tout[v];
		}; 
		
		auto lca = [&](int u, int v) -> int {
			for(int i=19; i >= 0; i--) {
				if (up[u][i] == -1)
					continue;
				
				int w = up[u][i];
				
				if (!is_ancestor(w, v))
					u = w;
			}
			
			return up[u][0];
		};
		
		calc(calc, i);
		
		mns.push_back(mn);
		
		for(int j=0; j < leaves.size(); j++) {
			for(int k=j+1; k < leaves.size(); k++) {
				int u = leaves[j];
				int v = leaves[k];
				
				ans = min(ans, s[u] + s[v] - s[lca(u, v)]);
			}
		}
	}
	
	sort(mns.begin(), mns.end());
	
	if (mns.size() >= 2)
		ans = min(ans, mns[0] + mns[1]);
		
	cout << ans << endl;
}