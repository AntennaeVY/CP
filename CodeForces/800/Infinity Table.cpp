#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int k;
		cin >> k;
		
		long long p;
		for(p=1; p*p < k; p++);
		
		if (k >= p*p - (p-1)) {
			cout << p << " " << p*p - k + 1 << endl;
		} else {
			cout << p - (p*p - (p-1) - k) << " " << p << endl;
		}
	}
}