#include<bits/stdc++.h>
using namespace std;

array<int, 3> dfs(int root, vector<vector<int>> &adj, string &colors) {
	array<int, 3> arr = {0, 0, 0};

	if (colors[root-1] == 'B') {
		arr[0] += 1;
	} else {
		arr[1] += 1;
	}
	
	if (adj[root].size() == 0) {
		return arr;
	}
	
	for(auto child : adj[root]) {
		array<int, 3> result = dfs(child, adj, colors);
		
		for(int i=0; i < 3; i++) {
			arr[i] += result[i];
		}
	}
	
	if (arr[0] == arr[1]) 
		arr[2] += 1;
		
	return arr;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<vector<int>> m(n+1, vector<int>());
		string s;
		
		for(int i=2; i <= n; i++) {
			int x;
			cin >> x;
			
			m[x].push_back(i);
		}
		
		cin >> s;
		
		cout << dfs(1, m, s)[2] << endl;
	}
}