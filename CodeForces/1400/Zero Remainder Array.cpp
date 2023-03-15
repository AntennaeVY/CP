#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		map<int, int> a;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			a[x%k]++;
		}
		
		long long ans = 0;
		
		for(auto &[i, j] : a) {
			if (i == 0)
				continue;
				
			ans = max(ans, ((k-i) + 1LL*k*(j-1)) + 1);
		}
		
		cout << ans << endl;
	}
}