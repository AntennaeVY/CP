#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> d(n);
		for(auto &di:d) cin >> di;
		
		sort(d.begin(), d.end());
		
		long long ans = d.back();
		
		for(int i=0; i < n; i++) {
			ans -= d[i];
		}
		
		long long cost = 0;
		
		for(int i=1; i < n; i++) {
			cost -= 1LL*d[i]*(n-1-i);
			cost += 1LL*d[i]*(i-1);
		}
		
		cout << ans - cost << endl;
	}
}