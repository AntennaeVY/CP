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
		
		vector<int> b(n);
		for(auto &bi : b) cin >> bi;
		
		vector<int> z(n);
		iota(z.begin(), z.end(), 0);
		
		sort(b.begin(), b.end());
		sort(z.begin(), z.end(), [&](int i, int j){
			return a[i] < a[j];
		});
		
		vector<int> ans(n);
		for(int i=0; i < n; i++) {
			ans[z[i]] = b[i];
		}
		
		for(int i=0; i < n; i++) {
			cout << ans[i] << " \n"[i == n-1];
		}
	}
}