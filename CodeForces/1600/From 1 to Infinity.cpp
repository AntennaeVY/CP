#include<bits/stdc++.h>
using namespace std;

long long c(long long k) {
	long long ten = 1;
	long long cnt = 0;
	
	for(long long i=1; i < 18; i++) {
		if (ten > k)
			break;
			
		cnt += i * (min(k, ten*10-1) - ten + 1);
		ten *= 10;
	}
	
	return cnt;
}

long long g(long long n) {
	if (n <= 0)
		return 0;
	
	return n*(n+1)/2;
}

long long f(long long k) {
	string n = "0" + to_string(k);
	long long ten = 1;
	long long sum = 0;

	for(long long i=n.size()-1; i > 0; i--) {
		long long p = stoll(n.substr(0, i));
		long long s = (i == n.size() - 1) ? 0LL : stoll(n.substr(i+1));
		long long d = stoll(n.substr(i, 1));
		 
		sum += g(9) * ten * p + g(d-1) * ten + d * (s+1); 
		
		ten *= 10;
	}
	
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;

	/*
		=> 428

		g(9) * 1 * 42 + g(7) * 1 + 8 * (s+1)
		g(9) * 10 * 4 + g(1) * 10 + 2 * (s+1)
		g(9) * 100 * 0 + g(3) * 100 + 4 * (s+1)
	*/

	while(t--) {
		long long k;
		cin >> k;
		
		long long l=0, r=1e16;
		while(l+1 < r) {
			long long m = l + (r-l)/2;
			
			if (c(m) <= k)
				l = m;
			else
				r = m;
		}
		
		long long ans = f(l);
		long long n = c(l);
		
		string s = to_string(l+1);
		for(long long i=0; i < s.size(); i++) {
			if (n == k)
				break;
				
			ans += s[i] - '0';
			n++;
		}
		
		cout << ans << "\n";
	}
}