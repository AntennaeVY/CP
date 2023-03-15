#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<pair<int, int>> ops = {{0, n-1}};
		
		for(int i=0; i < ops.size(); i++) {
			auto [l, r] = ops[i];
			int nl, nr;
			
			if (l == r)
				continue;
			
			if ((r-l+1)%2) {
				nl = l, nr = (l+r)/2 - 1;
				
				if (nr >= nl)
					ops.push_back({nl, nr});
					
				nl = (l+r)/2 + 1, nr = r;
				
				if (nr >= nl) 
					ops.push_back({nl, nr});
				
			} else {
				nl = l, nr = (l+r-1)/2 - 1;
				
				if (nr >= nl)
					ops.push_back({nl, nr});
					
				nl = (l+r-1)/2 + 1, nr = r;
				
				if (nr >= nl)
					ops.push_back({nl, nr});
			}
		}
		
		sort(ops.begin(), ops.end(), [](pair<int, int> &a, pair<int,int> &b) {
			if (a.second - a.first + 1 == b.second - b.first + 1)
				return a.first < b.first;
			else
				return a.second - a.first + 1 > b.second - b.first + 1;
		});
		
		vector<int> ans(n, 0);

		for(int i=0; i < n; i++) {
			auto &[l, r] = ops[i];
			
			if ((r-l+1) % 2)
				ans[(l+r)/2] = i+1;
			else
				ans[(l+r-1)/2] = i+1;
		}
		
		for(auto i : ans)
			cout << i << " ";
			
		cout << endl;
	}
}