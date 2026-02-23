#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int c = 1;
	
	while(true) {
		int n = 0;
		cin >> n;
		
		if (n == 0)
			break;
			
		vector<pair<int,int>> v(2*n);
		for(int i=0; i < 2*n; i++) {
			string _;
			cin >> _;
			
			cin >> v[i].first >> v[i].second;
		}
		
		function<long double(int, int)> calc_dist = [&](int i, int j) -> long double {
			int x1, y1, x2, y2;
			
			tie(x1, y1) = v[i];
			tie(x2, y2) = v[j];
			
			return sqrtl(1LL * (x2 - x1)*(x2 - x1) + 1LL * (y2 - y1)*(y2 - y1));
		};
		
		vector<long double> dp((1 << 2*n), -1);
		
		function<long double(int)> solve;
		solve = [&](int state) -> long double {
			if (state == (1 << 2*n) - 1)
				return 0;
			
			if (dp[state] > -0.5)
				return dp[state];
			
			int i = -1;
			for(i=0; i < 2*n; i++) {
				if ((state >> i & 1))
					continue;
					
				break;
			}
			
			long double minima = 1e18;
			
			for(int j=i+1; j < 2*n; j++) {
				if ((state >> j & 1))
					continue;
					
				int new_state = state | (1 << i) | (1 << j);
				
				minima = min(minima, calc_dist(i, j) + solve(new_state));
			}
			
			return dp[state] = minima;
		};
		
		cout << "Case " << c << ": ";
		cout << fixed << setprecision(2) << solve(0) << "\n";
		
		c++;
	}
}