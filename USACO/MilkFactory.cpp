#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("factory.in");
	ofstream fout("factory.out");
	
	int n;
	fin >> n;
	
	map<int, vector<int>> graph;
	map<int, int> visit_amount;
	map<int, bool> seen;
	
	for(int i=0; i < n-1; i++) {
		int u, v;
		fin >> u >> v;
		
		graph[u].push_back(v);
	}
	
	function<void(int)> dfs;
	dfs = [&](int x){
		seen[x] = true;
		
		for(auto y : graph[x]) {
			if (seen[y])
				continue;
			
			visit_amount[y]++;
			dfs(y);
		}
	};
	
	for(int i=1; i <= n; i++) {
		dfs(i);
		seen.clear();
	}
	
	for(int i=1; i <= n; i++) {		
		if (visit_amount[i] == n-1) {
			fout << i << endl;
			return 0;
		}
	}
	
	fout << -1 << endl;
}