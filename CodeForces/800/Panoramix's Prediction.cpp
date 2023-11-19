#include<bits/stdc++.h>
using namespace std;

bool is_prime(int i) {
	for(int j=2; j*j <= i; j++) {
		if (i % j == 0)
			return false;
	}
	
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i=n+1; i < m; i++) {
		if (is_prime(i)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	if (is_prime(m))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}