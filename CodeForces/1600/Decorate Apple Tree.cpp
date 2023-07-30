#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	map<int, vector<int>> graph;
	
	for(int i=2; i <= n; i++) {
		int pi;
		cin >> pi;
		
		graph[pi].push_back(i);
	}
	
	vector<int> ans;

	function<int(int)> dfs;
	dfs = [&](int v){
		if (graph[v].empty()) {
			ans.push_back(1);
			return 1;
		}
			
		int cnt = 0;
		for(auto u : graph[v]) {
			cnt += dfs(u);
		}
		
		ans.push_back(cnt);
		return cnt;
	}; 
	
	dfs(1);
	sort(ans.begin(), ans.end());
	
	for(auto x : ans) 
		cout << x << " ";
}