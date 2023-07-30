#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		
		sort(a.begin(), a.end());
		
		int mx = 0, l = 0;
		
		for(int r=1; r < n; r++) {
			if (a[r] - a[r-1] > k)
				l = r;
			
			mx = max(mx, r-l+1);
		}
		
		cout << n - mx << endl;
 	}
}