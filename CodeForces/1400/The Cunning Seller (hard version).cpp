#include<bits/stdc++.h>
using namespace std;

long long f(long long x) {
	return pow(3, x+1) + x * pow(3, x-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		long long n, k;
		cin >> n >> k;
		
		long long cnt = 0;
		vector<long long> ans(21); 
		while(n) {
			for(int i=0; i < 20; i++) {
				long long x = pow(3, i);
				
				if (x > n)
					break;
				
				ans[i] = n/x;
				cnt += n/x;
				n -= (n/x) * x;
			}
		}
		
		for(int i=0; i < 20; i++) {
			if (cnt <= k)
				break;
			
			long long c = min(ans[i] / 3, (cnt - k + 1)/2);
			
			ans[i] -= 3*c;
			ans[i+1] += c;
			cnt -= 2*c;
		}
		
		if (cnt > k) {
			cout << -1 << "\n";
			continue;
		}
		
		long long sum = 0;
		for(int i=0; i < 20; i++) {
			sum += ans[i] * f(i);
		}
		
		cout << sum << "\n";
	}
}