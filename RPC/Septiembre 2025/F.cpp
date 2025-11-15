#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int r, c;
	cin >> r >> c;
	
	vector<string> g(r);
	
	for(int i=0; i < r; i++) {
		cin >> g[i];
	}
	
	vector<vector<int>> v(r, vector<int>(c, 1e9));
	vector<vector<bool>> vis(r, vector<bool>(c));
	queue<pair<int,int>> q;	
	
	for(int i=0; i < r; i++) {
		for(int j=0; j < c; j++) {
			if (g[i][j] == 'W') {
				q.push({i, j});
				v[i][j] = 0;
				vis[i][j] = true;
			}
		}
	}
	
	vector<pair<int,int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for(auto [dx, dy] : d) {
			if (x + dx < 0 || y + dy < 0)
				continue;
				
			if (x + dx >= r || y + dy >= c)
				continue;
				
			if (vis[x+dx][y+dy])
				continue;
				
			vis[x+dx][y+dy] = true;
			q.push({x+dx, y+dy});
			
			v[x+dx][y+dy] = min(v[x+dx][y+dy], v[x][y] + 1);
		}
	}
	
	auto f = [&](int k) -> bool {
		vector<vector<bool>> done(r, vector<bool>(c, false));
		queue<pair<int,int>> qiu;
		
		if (v[0][0] >= k) {
			qiu.push({0, 0});
			done[0][0] = true;
		}
		
		while(!qiu.empty()) {
			auto [x, y] = qiu.front();
			qiu.pop();
			
			for(auto [dx, dy] : d) {
				if (x+dx < 0 || y+dy < 0)
					continue;
					
				if (x+dx >= r || y+dy >= c)
					continue;
					
				if (done[x+dx][y+dy])
					continue;
				
				if (v[x+dx][y+dy] >= k) {
					done[x+dx][y+dy] = true;	
					qiu.push({x+dx, y+dy});
				}
			}
		}
		
		return done[r-1][c-1];
	};
	
	int L=-1, R=1e9;
	while(L + 1 < R) {
		int m = L + (R-L)/2;
		
		if (f(m))
			L = m;
		else
			R = m;
	}
	
	cout << L << "\n";
}