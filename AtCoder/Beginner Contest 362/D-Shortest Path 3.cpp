#include<bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e18;

void dijkstra(
	int s, vector<long long> &d, vector<int> &p, vector<bool> &vis,
	map<int,vector<pair<int,long long>>> &graph , vector<int> &a
) {

	priority_queue<
		pair<long long, int>, 
		vector<pair<long long, int>>, 
		greater<pair<long long, int>>
	> pq; 
	
	
	d[s] = a[s];
	pq.push({d[s], s});
	
	while(!pq.empty()) {
		auto [_, from] = pq.top();
		pq.pop();
		
		if (vis[from])
			continue;
			
		vis[from] = true;
		
		for(auto [to, len] : graph[from]) {
			if (vis[to])
				continue;
				
			if (d[from] + len + a[to] >= d[to])
				continue;
				
			d[to] = d[from] + len + a[to];
			p[to] = from;
			
			pq.push({d[to], to});
		}
	}
}

int32_t main() {
	int n, m; 
	cin >> n >> m;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	map<int, vector<pair<int, long long>>> graph;
	
	for(int i=0; i < m; i++) {
		long long u, v, b;
		cin >> u >> v >> b;
		
		u--, v--;
		
		graph[u].push_back({v, b});
		graph[v].push_back({u, b});
	}
	
	vector<long long> d(n, INF);
	vector<int> p(n, -1);
	vector<bool> vis(n, false);
	
	dijkstra(0, d, p, vis, graph, a);
	
	for(int i=1; i < n; i++) {
		cout << d[i] << " ";
	}
	
	cout << endl;
}