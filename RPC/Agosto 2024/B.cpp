#include<bits/stdc++.h>
using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	
	vector<string> s(r);
	for(auto &si : s) cin >> si;
	
	map<pair<int,int>, vector<pair<int,int>>> g;
	
	for(int i=0; i < r; i++) {
		for(int j=0; j < c; j++) {
			int x = 0;
			
			for(int k=j+1; k < c; k++) {
				int my1 = s[i][j] - s[i][k];
				int mx1 = j - k;
				
				int my2 = s[i][j] - s[i][x];
				int mx2 = j - x;

				if (x == 0 || mx2*my1 >= my2*mx1) {
					x = k;
					
					g[{i, j}].push_back({i, x});
				}
			}
			
			x = 0;
			
			for(int k=i+1; k < r; k++) {
				int my1 = s[i][j] - s[k][j];
				int mx1 = i - k;
				
				int my2 = s[i][j] - s[x][j];
				int mx2 = i - x;
				
				if (x == 0 || mx2*my1 >= my2*mx1) {
					x = k;
					
					g[{i, j}].push_back({x, j});
				}
			}
		}
	}
	
	// for(auto &[u, c]: g) {
		// cout << u.first << "," << u.second << ": ";
// 		
		// for(auto v : c)
			// cout << v.first << "," << v.second << " ";
		// cout << endl;
	// }
// 	
	bool found = false;
	
	map<pair<int,int>, pair<int,int>> p;
	p[{0, 0}] = {-1, -1};
	
	map<pair<int,int>, bool> vis;
	
	queue<pair<int,int>> q;
	q.push({0, 0});
	
	while(!q.empty()) {
		pair<int,int> u = q.front();
		q.pop();
		
		vis[u] = true;
		
		for(auto v : g[u]) {
			if (!vis[v])
				q.push(v);
			
			if (p.find(v) == p.end())
				p[v] = u;		
		}
			
		int size = q.size();
			
		for(int i=0; i < size; i++) {
			auto &[x, y] = q.front();
			q.pop();
			
			vis[{x, y}] = true;
			
			for(auto z : g[{x, y}]) {
				if (!vis[z])
					q.push(z);
					
				if (p.find(z) == p.end())
					p[z] = {x, y};	
			}
			
			if (x == r-1 && y == c-1) {
				found = true;
				break;
			}
		}
		
		if (found)
			break;
	}
	
	// for(auto &[pi, pj] : p) {
		// cout << pi.first << "," << pi.second << " ";
		// cout << pj.first << "," << pj.second << endl;
	// }
	
	int ans = 0;
	
	int a = r-1, b = c-1;
	
	while(a != -1 || b != -1) {
		ans++;
		// cout << a << "," << b << " ";
		
		auto pi = p[{a, b}];
		
		a = pi.first, b = pi.second;
	}
	// cout << endl;
	
	cout << ans-2 << endl;
}