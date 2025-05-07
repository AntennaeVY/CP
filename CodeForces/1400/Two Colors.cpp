#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> a(m);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		long long ans = 0;
		
		for(int i=0; i < n-1; i++) {
			long long left = a.end() - lower_bound(a.begin(), a.end(), i+1);
			long long right = a.end() - lower_bound(a.begin(), a.end(), n-(i+1));
			
			ans += left*right - min(left, right);
		}
		
		cout << ans << endl;
	}
}