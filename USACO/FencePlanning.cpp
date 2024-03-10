#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> x(n+1), y(n+1);
	map<int, vector<int>> graph;
	
	for(int i=1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	
	for(int i=0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	vector<bool> vis(n+1);
	
	auto bfs = [&](int u){
		queue<int> q;
		q.push(u);
		
		int min_x = 1e9, min_y = 1e9;
		int max_x = -1, max_y = -1;
		
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			
			vis[v] = true;
			
			min_x = min(min_x, x[v]);
			max_x = max(max_x, x[v]);
			
			min_y = min(min_y, y[v]);
			max_y = max(max_y, y[v]);
			
			for(auto w : graph[v])
				if (!vis[w])
					q.push(w);
		}
		
		return 2 * (max_x - min_x + max_y - min_y);
	};
	
	int ans = 1e9;
	
	for(int i=1; i <= n; i++) {
		if (vis[i])
			continue;
			
		ans = min(ans, bfs(i));
	}
	
	cout << ans << endl;
}