#include<bits/stdc++.h>
using namespace std;

int dfs(map<int, vector<int>> &graph, vector<bool> &vis, int v) {
	vis[v] = true;
	int cnt = 1;
	
	for(auto u : graph[v]) {
		if (!vis[u])
			cnt += dfs(graph, vis, u);
	}
	
	return cnt;
}

bool construct_graph_and_check(vector<long long> &x, vector<long long> &y, int d) {
	map<int, vector<int>> graph;
	
	for(int i=0; i < x.size(); i++) {
		for(int j=i+1; j < y.size(); j++) {
			long long d2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
		
			if (d >= d2) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	
	vector<bool> vis(x.size(), false);
	
	int size = dfs(graph, vis, 0);
	
	if (size != x.size())
		return false;
		
	vis.assign(x.size(), false);
	
	dfs(graph, vis, 1);
	
	return vis[0];
}

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<long long> x(n), y(n);
	
	for(int i=0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	
	int l = -1, r = 1e9;
	
	while(l + 1 < r) {
		int m = l + (r-l)/2;
		
		if (construct_graph_and_check(x, y, m))
			r = m;
		else
			l = m;
	}
	
	cout << r << endl;
}