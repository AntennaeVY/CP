#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> v(n+1);
		for(int i=0; i < n; i++) {
			v[a[i]]++;
		}
		
		int ans = v[k];
		int x = 0;
		
		for(int i=0; i < k; i++) {
			if (!v[i])
				x++;
		}
			
		x -= v[k];
		ans += max(0, x);
		
		cout << ans << "\n";
	}
}