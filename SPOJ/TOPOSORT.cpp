#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	map<int, vector<int>> graph;
	map<int, int> indegree;
	
	for(int i=0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		
		graph[x].push_back(y);
		indegree[y]++;
	}
	
	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> q;
	
	for(int i=1; i <= n; i++) {
		if(indegree[i] == 0)
			q.push(i);
	}
		
	while(!q.empty()) {
		int v = q.top();
		q.pop();
		
		ans.push_back(v);
		
		for(auto u : graph[v]) {
			indegree[u]--;
			
			if (indegree[u] == 0)
				q.push(u);	
		}	
	}
	
	bool ok = true;

	for(int i=1; i <= n; i++) {
		if (indegree[i] != 0)
			ok = false;
	}
	
	if (!ok)
		cout << "Sandro fails.";
	else
		for(auto x : ans)
			cout << x << " ";
	
	cout << endl;
}