#include<bits/stdc++.h>
using namespace std;

long long ones(long long n, int i) {
	return (1LL << i) * ((n+1) / (1LL << (i+1))) + max(0LL, (n+1) % (1LL << (i+1)) - (1LL << i));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int q;
	cin >> q;
	
	while(q--) {
		long long l, r;
		cin >> l >> r;
		
		l = max(0LL, l-1);
		
		long long ans = 0;
	
		for(int i=0; i < 63; i++) {
			if ((1LL << i) > r)
				break;
			
			ans += 2 * (ones(r, i) - ones(l, i));
			
			long long x = ones(r, i) - ones(max(l, (1LL << i) - 1), i);
			long long y = (r-max(l, (1LL << i) - 1)) - x;
			
			ans += y;
		}
		
		cout << ans - (r-l) << "\n";
	}
}