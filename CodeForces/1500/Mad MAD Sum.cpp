#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> b(a);
		
		int mx = 0;
		long long ans = accumulate(a.begin(), a.end(), 0LL);
		long long sum = 0;
		
		for(int k=0; k < 2; k++) {
			ans += sum;
			
			map<int, int> cnt;
			sum = 0, mx = 0;
			
			for(int i=0; i < n; i++) {
				cnt[b[i]]++;
				
				if (cnt[b[i]] >= 2)
					mx = max(mx, b[i]);
					
				b[i] = mx;
				sum += mx;
			}
		}
		
		for(int i=n-1; i >= 0; i--) {
			ans += sum;
			sum -= b[i];
		}
		
		cout << ans << endl;
	}
}