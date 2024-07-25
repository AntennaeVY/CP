#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	map<int, vector<int>> tree;
	
	for(int i=2; i <= n; i++) {
		int p;
		cin >> p;
		
		tree[p].push_back(i);
	}
	
	map<int, int> cache;
	
	function<int(int)> dfs;
	dfs = [&](int x){
		int ans = tree[x].size();
		
		for(auto y : tree[x]) {
			ans += dfs(y);
		}
		
		return cache[x] = ans;
	};
	
	dfs(1);
	
	for(int i=1; i <= n; i++) {
		cout << cache[i] << " ";
	}
}