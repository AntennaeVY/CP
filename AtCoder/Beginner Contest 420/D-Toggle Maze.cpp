#include<bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int h, w;
	cin >> h >> w;
	
	vector<string> a(h);
	for(auto &ai : a) cin >> ai;
	
	int sx, sy, ex, ey;
	for(int i=0; i < h; i++) {
		for(int j=0; j < w; j++) {
			if (a[i][j] == 'S')
				sx = i, sy = j;
			if (a[i][j] == 'G')
				ex = i, ey = j;
		}
	}
	
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(h+5, vector<int>(w+5, INF)));
	vector<vector<vector<bool>>> v(2, vector<vector<bool>>(h+5, vector<bool>(w+5, false)));
	
	vector<pair<int,int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	
	queue<pair<int, pair<int,int>>> q;
	dp[0][sx][sy] = 0;
	
	v[0][sx][sy] = true;
	q.push({0, {sx, sy}});
	
	while(!q.empty()) {
		int C = q.front().first;
		
		pair<int,int> p = q.front().second;
		int x = p.first;
		int y = p.second;
		
		q.pop();
		
		int c = C;
		if (a[x][y] == '?')
				c ^= 1;
		
		for(auto [dx, dy] : d) {
			if (x + dx >= h || x + dx < 0)
				continue;
				
			if (y + dy >= w || y + dy < 0)
				continue;
			
			if (v[c][x+dx][y+dy] || a[x+dx][y+dy] == '#')
				continue;
				
			if (a[x+dx][y+dy] == 'o' && c == 1 || a[x+dx][y+dy] == 'x' && c == 0)
				continue;
				
			if (dp[c][x+dx][y+dy] != INF)
				continue;
				
			dp[c][x+dx][y+dy] = dp[C][x][y] + 1;
			
			v[c][x+dx][y+dy] = true;
			q.push({c, {x+dx, y+dy}});
		}
	}
	
	int ans = min(dp[0][ex][ey], dp[1][ex][ey]);
	
	cout << (ans == INF ? -1 : ans) << "\n";
}