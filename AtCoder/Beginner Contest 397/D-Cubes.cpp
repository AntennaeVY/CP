#include<bits/stdc++.h>
using namespace std;

long long sol(long long a, long long b, long long c) {
	long long l = 0, r = 1e9;
	
	while(l+1 < r) {
		long long mid = l + (r-l)/2;
		
		if (a*mid*mid + b*mid + c <= 0)
			l = mid;
		else
			r = mid;
	}
	
	if (a*l*l + b*l + c == 0)
		return l;
	
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n;
	cin >> n;
	
	for(long long d=1; d*d*d <= n; d++) {
		if (n % d != 0)
			continue;
			
		long long m = n/d; // d^2 + 3dk + 3k^2 = n/d; 
		
		long long k = sol(3, 3 * d, d*d - m);
		
		if (k > 0) {
			cout << d + k << " " << k << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
}