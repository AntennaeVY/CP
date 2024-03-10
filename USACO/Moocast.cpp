#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<int> h(n), k(n), r(n);
	
	for(int i=0; i < n; i++) {
		cin >> h[i] >> k[i] >> r[i];
	}
	
	map<int, vector<int>> graph;
	
	for(int i=0; i < n; i++) {
		for(int j=i+1; j < n; j++) {
			int d = (h[i] - h[j])*(h[i] - h[j]) + (k[i] - k[j])*(k[i] - k[j]);

			if (d <= r[i] * r[i])
					graph[i].push_back(j);
						
			if (d <= r[j] * r[j])
					graph[j].push_back(i);
		}
	}
	
	vector<bool> vis(n, false);
	
	function<int(int)> dfs;
	dfs = [&](int u){
		vis[u] = true;
		
		int cnt = 1;
		
		for(auto v : graph[u])
			if (!vis[v])
				cnt += dfs(v);
				
		return cnt;
	};
	
	int ans = 1;
	
	for(int i=0; i < n; i++) {
		ans = max(ans, dfs(i));
		
		vis.assign(n, false);
	}
	
	cout << ans << endl;
}