#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	map<int, vector<int>> graph;
	
	for(int i=0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	vector<bool> vis(n+1);
	vector<int> maxLength(n+1), toLeaf(n+1);
	
	function<int(int)> dfs;
	dfs = [&](int x){
		vis[x] = true;
		
		vector<int> children;
		
		for(auto y : graph[x]) {
			if (vis[y])
				continue;
			
			dfs(y);
			
			toLeaf[x] = max(toLeaf[x], toLeaf[y] + 1);
			children.push_back(toLeaf[y]);
		}
		
		sort(children.rbegin(), children.rend());
		
		if (children.size() >= 2)
			return maxLength[x] = children[0] + children[1] + 2;
		else if (children.size() == 1)
			return maxLength[x] = children[0] + 1;
		else
			return 0;
	};
	
	dfs(1);
	
	cout << *max_element(maxLength.begin(), maxLength.end()) << endl;
}