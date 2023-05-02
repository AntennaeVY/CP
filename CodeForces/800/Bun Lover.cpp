#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		long long n;
		cin >> n;
		
		long long ans = 4*n + ((n-1)*n)/2 + ((n-2)*(n-1))/2 + 1;
		
		cout << ans << endl;
	}
}