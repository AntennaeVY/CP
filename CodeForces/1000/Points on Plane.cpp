#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n;
		cin >> n;
		
		long long l = -1, r = 1e9;
		while(l + 1 < r) {
			long long mid = l + (r-l)/2;
			
			if ((mid)*(mid) >= n)
				r = mid;
			else
				l = mid;
		}
		
		cout << r-1 << endl;
	}
}