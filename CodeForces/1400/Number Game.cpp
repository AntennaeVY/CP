#include<bits/stdc++.h>
using namespace std;

int is_odd_prime(int n) {
	for(int i=2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	
	return true;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int m = n;
		while(m%2 == 0) m /= 2;
		
		if (n==1 || n!=2 && (m==1 || n%2 == 0 && n%4 != 0 && is_odd_prime(n/2)))
			cout << "FastestFinger" << endl;
		else
			cout << "Ashishgup" << endl;
	}
}