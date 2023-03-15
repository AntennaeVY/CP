#include<bits/stdc++.h>
using namespace std;

class DSU {
	private:
		vector<int> parent;
	public:
		DSU(int size) {
			parent.resize(size);
			fill(parent.begin(), parent.end(), -1);
		}
		
		int join(int x, int y) {
			if (parent[find(x)] > parent[find(y)])
				swap(x, y);
				
			if (find(x) == find(y))
				return find(x);
				
			parent[find(x)] += parent[find(y)];
			parent[find(y)] = find(x);
			
			return find(x);
		}
		
		int find(int x) {
			int root = x;
			
			while(parent[root] > 0)
				root = parent[root];
				
			// Path compression
			while(x != root) {
				int next = parent[x];
				parent[x] = root;
				x = next;
			}
			
			return root;
		}
};

bool count_edges(int root, map<int, bool> &visited, map<int, vector<int>> &graph) {
	if (visited[root])
		return false;
		
	visited[root] = true;
	
	bool exactly_2_edges = graph[root].size() == 2;
	
	for(auto child : graph[root]) {
		if (visited[child])
			continue;
			
		exactly_2_edges &= count_edges(child, visited, graph);
	}		
	
	return exactly_2_edges;
}


int main() {
	int n, m;
	cin >> n >> m;
	
	DSU dsu(n+1);
	map<int, vector<int>> graph;
	
	for(int i=0; i < m; i++) {
		int x,y;
		cin >> x >> y;
		
		graph[x].push_back(y);
		graph[y].push_back(x);
		
		dsu.join(x, y);
	}
	
	int ans = 0;
	map<int, bool> visited;
	
	for(int i=1; i <= n; i++) {
		ans += count_edges(dsu.find(i), visited, graph);
	}
	
	cout << ans << endl;
}