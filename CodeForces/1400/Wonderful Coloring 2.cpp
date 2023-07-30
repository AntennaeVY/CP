#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,k;
		cin >> n >> k;

		map<int, vector<int>> idx;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			if (idx[x].size() < k)
				idx[x].push_back(i);
		}
		
		int cnt = 0;
		
		for(auto v : idx) {
			cnt += v.second.size();
		}
		
		cnt -= cnt % k;
		
		int color = 0;
		vector<int> ans(n, 0);
		
		for(auto v : idx) {
			for (auto x : v.second) {
				if (cnt == 0) continue;
				
				ans[x] = ++color;
				color %= k;
				
				cnt--;
			}
		}
		
		for (auto x : ans) {
			cout << x << " ";
		}
		
		cout << endl;
	}
}