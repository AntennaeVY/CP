#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k, q;
		cin >> n >> k >> q;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int cnt = 0;
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			if (a[i] <= q)
				cnt++;
			else
				cnt = 0;	
				
			ans += max(0, cnt - k + 1);
		}
		
		cout << ans << endl;		
	}
}