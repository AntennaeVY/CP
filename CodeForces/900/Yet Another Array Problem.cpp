#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<long long> a(n);
		for(auto &ai : a) cin >> ai;
		
		long long gcd = a[0];
		for(int i=1; i < n; i++)
			gcd = __gcd(a[i], gcd);
			
		for(long long i=2; i*i <= 1e18; i++) {
			if (__gcd(i, gcd) != 1)
				continue;
				
			cout << i << "\n";
			break;
		}
	}
}