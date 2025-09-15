#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		for(int i=1; i < n; i+=2)
			swap(a[i], b[i]);
			
		map<int,int> ca, cb;
		
		int ans = 0;
		
		for(int i=n-1; i >= 0; i--) {
			if (
				a[i] == b[i] || 
				ca[b[i]] || 
				cb[a[i]] || 
				ca[a[i]] - i > 1 || 
				cb[b[i]] - i > 1
			) {
				ans = i+1;
				break;
			}
			
			ca[a[i]] = max(ca[a[i]], i);
			cb[b[i]] = max(cb[b[i]], i);
			
		}
		
		// for(auto &ai : a)
			// cout << ai << " ";
		// cout << "\n";
		// for(auto &bi : b)
			// cout << bi << " ";
		// cout << "\n";
		
		cout << ans << "\n";
	}
}