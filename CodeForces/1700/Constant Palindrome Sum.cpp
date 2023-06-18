#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int, int> cnt;
		for(int i=0; i < n/2; i++) {
			cnt[a[i] + a[n-1-i]] += 1;
		}
		
		vector<int> p(2*k+1, 0);
		for(int i=0; i < n/2; i++) {
			int l = min(a[i], a[n-1-i]) + 1;
			int r = max(a[i], a[n-1-i]) + k;
			
			p[l] += 1;
			p[r+1] -= 1;
		}
		
		for(int i=0; i < 2*k; i++) {
			p[i+1] += p[i];
		}
		
		int ans = 1e9;
		
		for(int i=1; i <= 2*k; i++) {
			ans = min(ans, n - p[i] - cnt[i]);
		}
		
		cout << ans << endl;
	}
}