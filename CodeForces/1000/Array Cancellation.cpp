#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<long long> a(n);
		for(auto &ai:a) cin >> ai;
		
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			long long temp = min(ans, abs(a[i]));
			
			if (a[i] > 0)
				ans += a[i];
			else if (a[i] < 0) {
				a[i] += temp;
				ans -= temp;
			}
		}
		
		cout << ans << endl;
	}
}