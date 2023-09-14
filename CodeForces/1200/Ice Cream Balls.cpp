#include<bits/stdc++.h>
using namespace std;

bool check(long long x, long long n) {
	return (x * (x-1)) / 2 <= n;
}

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		long long n;
		cin >> n;
		
		long long l=0, r=1e10;
		while(l+1 < r) {
			long long x = l + (r-l)/2;
			
			if (check(x, n))
				l = x;
			else
				r = x;
		}
		
		cout << l + n - (l * (l-1))/2 << endl;
	}
}