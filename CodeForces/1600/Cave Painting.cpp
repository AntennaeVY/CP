#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	
	if (k >= 43) {
		cout << "No" << endl;
	} else {
		bool ok = true;
		
		for(int i=1; i <= k; i++) {
			ok &= ((n+1) % i == 0);
		}
		
		cout << (ok ? "Yes" : "No") << endl;
	}
}