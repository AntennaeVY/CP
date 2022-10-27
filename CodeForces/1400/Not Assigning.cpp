#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<vector<int>> adjacency(n+1);
		vector<int> degree(n+1, 0);
		map<pair<int,int>, int> position;
		vector<bool> visited(n+1, false);
		
		vector<int> ans(n);
		
		for(int i=1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			
			adjacency[u].push_back(v);
			adjacency[v].push_back(u);
			
			degree[u]++;
			degree[v]++;
			
			position[{u, v}] = i;
			position[{v, u}] = i;
		}
		
		int start = -1, end = -1;
		bool invalid = false;
		
		for(int i=1; i <= n; i++) {
			if (degree[i] > 2) {
				invalid = true;
			}
			
			if (degree[i] == 1 && start == -1) 
				start = i;
			else if (degree[i] == 1 && start != -1)
				end = i;
		}
		
		if (invalid) {
			cout << -1 << endl;
			continue;
		}
		
		int current = start, weight = 2;
		
		while(current != end) {
			int next = adjacency[current][0];
			
			if (visited[next]) 
				next = adjacency[current][1];

			ans[position[{next, current}]] = weight;
			
			weight = 3 - weight%2;
			
			visited[current] = true;
			current = next;
		}
		
		for(int i=1; i < n; i++) {
			cout << ans[i] << " ";
		}
		
		cout << endl;
	}
}