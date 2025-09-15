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
		long long n;
		cin >> n;
		
		long long cnt = 0;
		
		while(n) {
			long long l=0, r=20;
			while(l+1 < r) {
				long long m = l + (r-l)/2;
				
				if (pow(3, m) <= n)
					l = m;
				else
					r = m;
			}
			n -= 1LL * pow(3, l);
			cnt += 1LL * f(l);
		}
		
		assert(n == 0);
		cout << cnt << "\n";
	}
}