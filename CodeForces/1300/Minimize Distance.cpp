#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,k;
		cin >> n >> k;
		
		int mx = 0;
		long long ans = 0;
		vector<int> pos, neg;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			if (x > 0)
				pos.push_back(x);
			else 
				neg.push_back(-x);
				
			mx = max(mx, abs(x));
		}
		
		sort(pos.rbegin(), pos.rend());
		sort(neg.rbegin(), neg.rend());
		
		for(int i=0; i < pos.size(); i+=k) {
			ans += 2*pos[i];
		}		
		
		for(int i=0; i < neg.size(); i+=k) {
			ans += 2*neg[i];
		}
		
		ans -= mx;
		
		cout << ans << endl;
	}
}