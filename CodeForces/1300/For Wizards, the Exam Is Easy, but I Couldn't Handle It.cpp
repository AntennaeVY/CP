#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<vector<pair<int,int>>> m(n, vector<pair<int,int>>(n, {0, 0}));
		
		int l = 0, r = 0;
		int min_delta = 1e9;
		
		for(int i=0; i < n; i++) {
			for(int j=i; j < n; j++) {
				auto [mn, mx] = m[i][max(j-1, 0)];
				
				m[i][j].first = mn;
				m[i][j].second = mx;
				
				if (a[j] < a[i])
					m[i][j].first++, mn++;
				
				if (a[j] > a[i])
					m[i][j].second++, mx++;
					
				if (mx-mn < min_delta) {
					l = i, r = j;
					min_delta = mx-mn;
				}
			}
		}
		
		cout << l+1 << " " << r+1 << '\n';
	}
	
}