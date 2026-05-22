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
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		long long cnt = 0;
		int mn = a[n-1] + 1;
	
		for(int i=n-1; i >= 0; i--) {
			if (a[i] < mn) {	
				mn = a[i];
			}
				
			cnt += a[i] - mn;
			a[i] = mn;
		}
		
		map<int,long long> m;
		for(int i=0; i < n; i++) {
			m[a[i]] += 1;
		}
		
		long long mx = 0;
		long long sum = 0;
		
		for(int i=n-1; i >= 0; i--) {
			m[a[i]] -= 1;
			mx = max(mx, m[a[i]]);
		}
		
		cout << cnt + mx << "\n";
	}
}