#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	vector<long long> fact(15, 0);
	fact[0] = fact[1] = 1;
	
	for(int i=2; i < 15; i++) {
		fact[i] = fact[i-1]*i;
	}
	
	while(t--) {
		long long n;
		cin >> n;
		
		int mn = __builtin_popcountll(n);
		
		for(int i=0; i < (1 << 15); i++) {
			long long sum = 0;
			
			for(int j=2; j <= 14; j++) {
				if ((i >> j) & 1)
					sum += fact[j];
			}
			
			if (sum > n || (i ^ 3) != i + 3)
				continue;
				
			mn = min(mn, __builtin_popcountll(i) + __builtin_popcountll(n-sum));
		}
		
		cout << mn << endl;
	}
	

}