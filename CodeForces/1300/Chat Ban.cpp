#include<bits/stdc++.h>
using namespace std;

bool good(long long mid, long long x, long long k) {
	if (mid > k) {
		return (k*(k+1)/2 + k*(k-1)/2 - (k-(mid-k))*(k-(mid-k)+1)/2 + k-(mid-k)) < x;
	} else {
		return ((mid)*(mid+1)/2) < x;
	}
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long k, x;
		cin >> k >> x;
		
		long long l = 0, r = 2*k-1;
		
		while(l+1 < r) {
			long long mid = l + (r-l)/2; 
			
			if (!good(mid, x, k)) 
				r = mid;
			else
				l = mid;
		} 
		
		cout << r << endl;
	}
}