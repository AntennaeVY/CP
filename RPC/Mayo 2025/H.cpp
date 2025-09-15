#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	for(int c=1; c <= t; c++) {
		int h, w;
		cin >> h >> w;
		
		vector<string> m(h);
		for(auto &mi : m) cin >> mi;
		
		vector<vector<int>> vis(h, vector<int>(w));
		vector<pair<int,int>> d = {
			{-1,  0},
			{ 1,  0},
			{ 0, -1},
			{ 0,  1}
		};
	
		int R = 0, T = 0, D = 0;
		
		function<void(pair<int,int>)> bfs;
		bfs = [&](pair<int,int> p) {
			int size = 0, dist = -1;
			pair<int,int> a, b;
			
			queue<pair<int,int>> q;
			q.push(p);
			
			while(!q.empty()) {
				auto [x, y] = q.front();
				q.pop();
				
				size++;
				vis[x][y] = 1;
				
				for(auto [dx, dy] : d) {
					if (x + dx < 0 || x + dx >= h)
						continue;
					
					if (y + dy < 0 || y + dy >= w)
						continue;
						
					if (vis[x+dx][y+dy] || m[x+dx][y+dy] == '#')
						continue;
						
					q.push({x+dx, y+dy});
				}
				
				a = {x, y};
			}
			
			q.push(a);
			
			while(!q.empty()) {
				int n = q.size();
				
				while(n--) {
					auto [x, y] = q.front();
					q.pop();
					
					vis[x][y] = 2;
					
					for(auto [dx, dy] : d) {
						if (x + dx < 0 || x + dx >= h)
							continue;
						
						if (y + dy < 0 || y + dy >= w)
							continue;
							
						if (vis[x+dx][y+dy] == 2 || m[x+dx][y+dy] == '#')
							continue;
							
						q.push({x+dx, y+dy});
					}
					
					b = {x, y};
				}
				
				dist++;
			}
			
			R++;
			
			if (size > T) {
				T = size;
				D = dist;
			}
			
			if (size == T) {
				D = max(D, dist);
			}
		};
		
	
		for(int i=0; i < h; i++) {
			for(int j=0; j < w; j++) {
				if (m[i][j] == '#')
					continue;
				
				if (vis[i][j])
					continue;
					
				bfs({i, j});
			}
		}
		
		cout << "Case " << c << ": " << R << " " << T << " " << D << "\n";
	}
}