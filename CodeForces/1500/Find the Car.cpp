#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k, q;
		cin >> n >> k >> q;
		
		vector<int> a(k+1, 0), b(k+1, 0);
		
		for(int i=1; i <= k; i++) {
			cin >> a[i];
		}
		
		for(int i=1; i <= k; i++) {
			cin >> b[i];
		}
		
		while(q--) {
			long long d;
			cin >> d;
			
			int l = -1, r = k;
			while(l+1 < r) {
				int m = l + (r-l)/2;
				
				if (a[m] >= d)
					r = m;
				else
					l = m;
			}
			
			int x = r;
			
			if (a[x] == d) {
				cout << b[x] << " ";
				continue;
			}
			
			long long ans = b[x-1] + (d - a[x-1]) * (b[x] - b[x-1]) / (a[x] - a[x-1]);
		
			cout << ans << " ";
		}
		
		cout << "\n";
	}
}