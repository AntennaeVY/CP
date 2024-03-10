#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n, m, x;
		cin >> n >> m >> x;
		
		long long up = (x + n - 1) % n;
		long long left = (x - 1)/ n;
		
		cout << up * m + left + 1 << endl;
	}
}