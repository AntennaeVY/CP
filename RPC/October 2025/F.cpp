#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<string> v(n);
	for(auto &vi : v) cin >> vi;
	
	int mx = 0;
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			// cout << v[i][j] << endl;
			if (v[i][j] != '+')
				continue;
				
			int su = 0, sd = 0;
			int sl = 0, sr = 0;
			int sul = 0, sur = 0, sdl = 0, sdr = 0;
			
			// up
			for(int k=1; i-k >= 0; k++) {
				su += (v[i-k][j] == '|');
				
				if (v[i-k][j] != '|')
					break;
			}
			
			// cout << "UP: " << su << endl; 
			
			// down
			for(int k=1; i+k < n; k++) {
				sd += (v[i+k][j] == 124);
				
				if (v[i+k][j] != 124)
					break;
			}
			
			// cout << "DOWN: " << sd << endl;
			
			// right
			for(int k=1; j+k < m; k++) {
				sr += (v[i][j+k] == 45);
				
				if (v[i][j+k] != 45)
					break;
			}
			
			// cout << "RIGHT: " << sr << endl;
			
			// left
			for(int k=1; j-k >= 0; k++) {
				sl += (v[i][j-k] == 45);
				
				if (v[i][j-k] != 45)
					break;
			}
			
			// cout << "LEFT: " << sl << endl;
			
			// UL diagonal
			for(int k=1; i-k >= 0 && j-k >= 0; k++) {
				sul += (v[i-k][j-k] == 92);
				
				if (v[i-k][j-k] != 92)
					break;
			}
			
			// cout << "UP-LEFT: " << sul << endl;
			
			// DR diagonal
			for(int k=1; i+k < n && j+k < m; k++) {
				sdr += (v[i+k][j+k] == 92);
				
				if (v[i+k][j+k] != 92)
					break;
			}
			
			// cout << "DOWN-RIGHT: " << sdr << endl;
		
			// UR diagonal
			for(int k=1; i-k >= 0 && j+k < m; k++) {
				sur += (v[i-k][j+k] == 47);
				
				if (v[i-k][j+k] != 47)
					break;
			}
			
			// cout << "UP-RIGHT: " << sur << endl;
			
			// DL diagonal
			for(int k=1; i+k < n && j-k >= 0; k++) {
				sdl += (v[i+k][j-k] == 47);
				
				if (v[i+k][j-k] != 47)
					break;
			}
			
			// cout << "DOWN-LEFT: " << sdl << endl;
			
		
			int sd1 = min(sul, sdr);
			int sd2 = min(sur, sdl);
			int x = min(sl, sr);
			int y = min(su, sd);
			
			// cout << sd1 << " " << sd2 << " " << x << " " << y << endl;
			
			mx = max(mx, min({sd1, sd2, x, y}));
		}
	}
	
	cout << mx << "\n";
}