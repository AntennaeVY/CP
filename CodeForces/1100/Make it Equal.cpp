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
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		map<int,int> ma, mb;
		for(int i=0; i < n; i++) {
			int cl = min(a[i] % k, abs(a[i] % k - k));
			int cl2 = min(b[i] % k, abs(b[i] % k - k));
			
			ma[cl] += 1;
			mb[cl2] += 1;
		}
		
		bool ok = true;
		
		for(auto &[bi, c] : mb) {
			int cl = min(bi, abs(bi - k) % k);
			
			if (ma[cl] != c)
				ok = false;
		}
	
		
		cout << (ok ? "YES" : "NO") << "\n";
	}
}