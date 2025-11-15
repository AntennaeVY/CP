#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, k, x;
		cin >> n >> k >> x;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		int l=0, r=x+1;
		while(l+1 < r) {
			int m = l + (r-l)/2;

			int cnt = 0;
			
			if (a[0] - m >= 0) {
				cnt += a[0] - m + 1;
			}
			
			if (a[n-1] + m <= x) {
				cnt += x - a[n-1] - m + 1;
			}
			
			for(int i=1; i < n; i++) {
				if (max(a[i] - m, 0) < min(a[i-1] + m, x))
					continue;
					
				cnt += max(a[i] - m, 0) - min(a[i-1] + m, x) + 1;
			}
		
			// cout << m << " " << cnt << endl;
			
			
			if (cnt >= k)
				l = m;
			else
				r = m;
		}
		
		set<int> ans;
		
		for(int i=0; i <= a[0] - l; i++) {
			if (ans.size() == k)
				break;
		
			ans.insert(i);
		}
		
		for(int i=x; i >= a[n-1] + l; i--) {
			if (ans.size() == k)
				break;
				
			ans.insert(i);
		}
		
		for(int i=1; i < n; i++) {
			if (max(a[i] - l, 0) < min(a[i-1] + l, x))
				continue;
				
			if (ans.size() == k)
				break;
				
			for(int j=min(a[i-1] + l, x); j <= max(a[i] - l, 0); j++) {
				if (ans.size() == k)
					break;
					
				ans.insert(j);
			}
		}
		
		for(auto &ansi : ans)
			cout << ansi << " ";
		cout << "\n";
	}
}