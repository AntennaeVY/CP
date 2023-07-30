#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<long long> p(n);
		for(auto &pi:p) cin >> pi;
		
		long long sum = p[0], ans = 0;
		
		for(int i=1; i < n; i++) {
			long long change = (p[i]*100LL - k*sum + k-1)/k;
			
			if (p[i]*100LL > k*sum) {
				ans += change;
				p[i] += change;
			}
			
			sum += p[i];
		}
		
		cout << ans << endl;
	}
}