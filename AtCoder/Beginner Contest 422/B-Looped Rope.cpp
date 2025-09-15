#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int h, w;
	cin >> h >> w;
	
	vector<string> v(h);
	for(auto &vi : v) cin >> vi;
	
	vector<pair<int,int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	bool ok = true;
	for(int i=0; i < h; i++) {
		for(int j=0; j < w; j++) {
			int cnt = 0;
			
			if (v[i][j] == '.')
				continue;
			
			for(auto [di, dj] : d) {
				if (i + di >= h || i + di < 0)
					continue;
					
				if (j + dj >= w || j + dj < 0)
					continue;
					
				cnt += v[i+di][j+dj] == '#';
			}
			
			ok &= (cnt == 2 || cnt == 4);
		}
	}
	
	cout << (ok ? "Yes" : "No") << "\n";
}