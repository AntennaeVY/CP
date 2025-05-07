#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int k;
		cin >> k;
	
		if (k == 0) {
			cout << 0 << '\n';
			continue;
		}
		
		int x = 1, y = 1;
		
		vector<pair<int,int>> ans;
	
		while(k) {
			int m;
			
			for(int i=500; i >= 0; i--) {
				if (i * (i-1) / 2 <= k) {
					m = i;
					break;
				}
			}
			
			for(int i=0; i < m; i++)
				ans.push_back({x++, y});
			
			y++, k -= m*(m-1)/2;
		}
		
		cout << ans.size() << "\n";
		for(auto &[x, y] : ans)
			cout << x << " " << y << "\n";
	}
}