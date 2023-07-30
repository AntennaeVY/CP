#include<bits/stdc++.h>
using namespace std;

int ans = 0, tot_red = 0, tot_blue = 0;
bool red[300005], blue[300005];
map<int, vector<int>> graph;

pair<int, int> dfs(int x, int p) {
	int curr_red = red[x], curr_blue = blue[x];
	
	for(int u : graph[x]) {
		if (u == p)
			continue;
			
		auto tmp = dfs(u, x);
		curr_red += tmp.first;
		curr_blue += tmp.second; 
	}
	
	if ((tot_red - curr_red == 0) && curr_blue == 0 || (tot_blue - curr_blue == 0) && curr_red == 0)
		ans++;
	
	return {curr_red, curr_blue};
}

int main() {
	int n;
	cin >> n;
	
	for(int i=0; i < n; i++) {
		int c;
		cin >> c;
		
		if (c == 1)
			red[i+1] = 1, tot_red++;
		else if (c == 2)
			blue[i+1] = 2, tot_blue++;
	}
	
	for(int i=0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	dfs(1, -1);
	cout << ans << endl;
}