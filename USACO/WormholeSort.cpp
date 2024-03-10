#include<bits/stdc++.h>
using namespace std;


int main() {
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> p(n);
	for(auto &pi : p) {
		cin >> pi;
		pi--;
	}
	
	bool sorted = true;
	for(int i=0; i < n; i++) {
		sorted &= (p[i] == i);
	}
	
	if (sorted) {
		cout << -1 << endl;
		return 0;
	}
	
	int w_max = 0;
	vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
	
	for(int i=0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		
		--a, --b;
		
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
		
		w_max = max(w_max, w);
	}
	
	int l=0, r=w_max+1;
	
	while(l+1 < r) {
		int x = l + (r-l)/2;
		
		int c = 0;
		vector<int> component(n, -1);
		
		for(int i=0; i < n; i++) {
			if (component[i] != -1)
				continue;
				
			stack<int> s;
			s.push(i);
			
			while(!s.empty()) {
				int u = s.top();
				s.pop();
				
				component[u] = c;
				
				for(auto &[v, w] : graph[u]) {
					if (component[v] == -1 && w >= x) 
						s.push(v);
				}
			}
			
			c++;
		}
		
		bool can = true;
		
		for(int i=0; i < n; i++) {
			can &= (component[i] == component[p[i]]);
		}
		
		if (can)
			l = x;
		else
			r = x;
	}
	
	cout << l << endl; 
}