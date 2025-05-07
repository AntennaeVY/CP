#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		long long n, m, k;
		cin >> n >> m >> k;
		
		long long l=0, r=m;
		while(l+1 < r) {
			long long x = l + (r-l)/2;
			
			long long row = x * (m / (x+1)) + m % (x + 1);
			long long cnt = row * n;
			
		
			if (cnt >= k) {
				r = x;
			} else {
				l = x;
			}
		}
		
		cout << r << endl;
	}
}