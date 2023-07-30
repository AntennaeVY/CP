#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adjacency_list;

int dfs(int root, set<int> &sv, map<int, bool> &seen) {
	seen[root] = true;
	int ans = sv.count(root);
	
	if (sv.count(root)) {
		sv.erase(root);
	}
	
	for(int server : adjacency_list[root]) {
		if (seen[server]) continue;
		
		ans += dfs(server, sv, seen);
	}
	
	return ans;
}


int main() {
	int n;
	cin >> n;
	
	for(int i=0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		
		adjacency_list[a].push_back(b);
		adjacency_list[b].push_back(a);
	}
	
	int q;
	cin >> q;
	
	for(int i=0 ; i < q; i++) {
		int x, k;
		cin >> x >> k;
		
		map<int, bool> seen;
		set<int> servers_ids;
		
		vector<int> servers;
		
		for(int j=0; j < k; j++) {
			int ki;
			cin >> ki;
			
			servers_ids.insert(ki);
			servers.push_back(ki);
		}
		
		// DFS from X and check if it has connection with each K
		cout << dfs(x, servers_ids, seen) << " ";
		
		for(int server : servers) {
			if (!servers_ids.count(server)) {
				cout << server << " ";
			}
		}
		
		cout << endl;
	}
	
}