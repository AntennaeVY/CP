#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long a, b, k;
		
		cin >> a >> b >> k;
		
		long long m = a - b;
		
		long long pos = (a-b)*(k/2);
		
		pos += a * (k%2);
		
		cout << pos << endl;
	}
}