#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	map<int, vector<int>> g;
	vector<int> start;
	
	for(int i=0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		
		if (a == 0 && b == 0) {			
			start.push_back(i);
			continue;	
		}
		
		a--, b--;
		
		g[a].push_back(i);
		g[b].push_back(i);
	}

	int m = start.size();	
	
	queue<int> q;
	vector<bool> vis(n);
	
	for(int i=0; i < m; i++) {
		q.push(start[i]);
		vis[start[i]] = true;
	}
	
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(auto y : g[x]) {
			if (!vis[y]) {	
				q.push(y);
				vis[y] = true;
			}
		}
	}
	
	int ans = 0;
	for(int i=0; i < n; i++)
		ans += (vis[i]);
	
	cout << ans << "\n";
}
