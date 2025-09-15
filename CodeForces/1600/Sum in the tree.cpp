#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	map<int, vector<int>> g;
	vector<long long> p(n), s(n), a(n);
	long long sum = 0;
	
	for(int u=1; u < n; u++) {
		int v;
		cin >> v;
		
		v--;
		
		g[v].push_back(u);
		p[u] = v;
	}
	
	for(int i=0; i < n; i++)
		cin >> s[i];
		
	a[0] = s[0];
		
	int h = 1;
	bool can = true;
	
	queue<int> q;
	q.push(0);
	
	while(!q.empty()) {
		int m = q.size();
		
		for(int i=0; i < m; i++) {
			int u = q.front();
			q.pop();
			
			long long mn = g[u].size() ? 2e9 : 0;
			
			for(auto &v : g[u]) {
				if (h > 1)
					mn = min(mn, s[v] - s[p[u]]);
				q.push(v); 
			}
			
			if (h % 2) {
				if (h > 1)
					a[u] = s[u] - s[p[u]];
			} else {
				a[u] = mn;
				s[u] = s[p[u]] + mn;
			}
			
			if (a[u] < 0)
				can = false;
			
			sum += a[u];
		}
		
		h++;
	}
	
	if (!can) {
		cout << "-1\n";
		return 0;
	}
	
	cout << sum << '\n';
}