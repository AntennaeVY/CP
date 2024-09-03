#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int l, r;
		cin >> l >> r;
		
		long long L=0, R=1E9;
		while(L + 1 < R) {
			long long m = L + (R-L)/2;
			
			if (l + m*(m+1)/2 <= r)
				L = m;
			else
				R = m;
		}
		
		cout << L + 1 << endl;
	}
}