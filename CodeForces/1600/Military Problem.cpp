#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	vector<int> sequence(n);
	map<int, int> size, index;
	map<int, vector<int>> graph;
	
	for(int i=2; i <= n; i++) {
		int pi;
		cin >> pi;
		
		graph[pi].push_back(i);
	}
	
	function<int(int)> calculate_size;
	calculate_size = [&](int root){
		if (graph[root].empty())
			return 0;
			
		for(int child : graph[root]) {
			size[root] += 1 + calculate_size(child);
		}
		
		return size[root];
	};
	
	function<void(int, int&)> dfs;
	dfs = [&](int x, int &i){		
		index[x] = i;
		sequence[i] = x;
		
		for(int u : graph[x]) {
			dfs(u, ++i);		
		}
	};

	int i=0;
		
	calculate_size(1);
	dfs(1, i);
	
	while(q--) {
		int u, k;
		cin >> u >> k;
		
		if (size[u] < k - 1)
			cout << -1 << endl;
		else
			cout << sequence[index[u] + k - 1] << endl;
	}
}