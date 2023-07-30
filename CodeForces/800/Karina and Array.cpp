#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		int n;
		cin >> n;
		
		vector<int> pos, neg;
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			if (x >= 0)
				pos.push_back(x);
			else
				neg.push_back(x);
		}
		
		sort(pos.rbegin(), pos.rend());
		sort(neg.begin(), neg.end());
		
		long long ans = -1e18;
		
		if (pos.size() >= 2)
			ans = max(ans, 1LL * pos[0] * pos[1]);
		
		if (neg.size() >= 2)
			ans = max(ans, 1LL * neg[0] * neg[1]);
			
		if (!pos.empty() && !neg.empty())
			ans = max(ans, 1LL * pos[0] * neg[0]);
			
		cout << ans << endl; 
	}
}