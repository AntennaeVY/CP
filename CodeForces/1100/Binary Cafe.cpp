#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		if (k >= __lg(n) + 1) {
			cout << n+1 << endl;
			continue;
		}
		
		
		cout << (1LL << k) << endl;
	}
}