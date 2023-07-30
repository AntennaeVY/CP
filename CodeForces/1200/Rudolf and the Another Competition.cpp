#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, m, h;
		cin >> n >> m >> h;
		
		vector<vector<int>> t(n, vector<int>(m));
		vector<long long> x(n, 0), y(n, 0), z(n);
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cin >> t[i][j];
			}
		}
		
		for(int i=0; i < n; i++) {
			sort(t[i].begin(), t[i].end());
		
			long long time = 0;
			
			for(int j=0; j < m; j++) {
				if (time + t[i][j] <= h)
					x[i] += time + t[i][j], y[i]++;
					
				time += t[i][j];
			}
		}
		
		iota(z.begin(), z.end(), 0);
		
		sort(z.begin(), z.end(), [&](int i, int j) {
			if (y[i] == y[j] && x[i] == x[j])
				return i == 0;
			
			if (y[i] == y[j])
				return x[i] < x[j];
				
			return y[i] > y[j];
		});
		
		int place = 0;
		
		for(int i=0; i < n; i++) {
			if (z[i] == 0)
				place = i+1;
		}
		
		cout << place << endl;
	}
}