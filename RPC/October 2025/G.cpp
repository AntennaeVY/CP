#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	map<string, vector<string>> g;
	set<string> names;
	
	for(int i=0; i < n; i++) {
		string a, b, input;
		
		cin >> a;
		cin >> input >> input;
		cin >> b;
		
		a.pop_back();
		
		g[b].push_back(a);
		
		names.insert(b);
		names.insert(a);
	}
	
	map<string, bool> vis;
	int cnt = 0;
	
	auto dfs = [&](auto &&self, string &u) -> void {
		vis[u] = true;
		cnt += 1;
		
		for(auto &v : g[u])
			if (!vis[v])
				self(self, v);
	};
	
	string v = "";
	int m = names.size();
	
	for(auto i : names) {
		if (vis[i])
			continue;
			
		dfs(dfs, i);
		
		if (cnt == m) {
			v = i;
			break;
		}
	}
	
	vis.clear();
	cnt = 0;
	
	dfs(dfs, v);
	
	if (cnt == m)
		cout << "possible\n";
	else
		cout << "impossible\n";
}