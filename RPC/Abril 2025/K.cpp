#include<bits/stdc++.h>
using namespace std;

vector<string> rotate90(vector<string> &v) {
	int n = v.size();
	int m = v[0].size();
	
	vector<string> ans;
	
	for(int j=0; j < m; j++) {
		string row = "";
		
		for(int i=n-1; i >= 0; i--) {
			row += v[i][j];
		}
		
		ans.push_back(row);
	}
	
	// debug
		// for(int i=0; i < ans.size(); i++) {
			// cout << ans[i] << endl;
		// }
		// cout << endl;
	// end-debug
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int r, c;
	cin >> r >> c;
	
	vector<vector<int>> g(r, vector<int>(c));
	for(int i=0; i < r; i++) {
		for(int j=0; j < c; j++) {
			cin >> g[i][j];
		}
	}
	
	int s, t;
	cin >> s >> t;
	
	vector<string> f(s);
	for(int i=0; i < s; i++) {
		cin >> f[i];
	}
	
	long long sum = 0;
	for(int i=0; i < r; i++) {
		sum += accumulate(g[i].begin(), g[i].end(), 0LL);
	}
	
	long long mx = 0;
	
	for(int _=1; _ <= 4; _++) {
		f = rotate90(f);
		s = f.size();
		t = f[0].size();
		
		

		for(int i=0; i < r; i++) {
			for(int j=0; j <= c; j++) {
				
				long long curr = sum;
				bool can = true;
				
				for(int L=0; L < s; L++) {
					for(int R=0; R < t; R++) {
						if (f[L][R] == '.')
							continue;
							
						if (i+L >= r || j+R >= c) {
							can = false;
							break;
						}
							
						curr -= g[i+L][j+R];
					}
				}
				
				if (can)				
					mx = max(mx, curr);
			}
		}
	}
	
	cout << mx << endl;
}