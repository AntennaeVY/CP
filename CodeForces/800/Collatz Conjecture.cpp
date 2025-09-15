#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		long long k, x;
		cin >> k >> x;
		
		while(k--)
			x *= 2;
			
		cout << x << endl;
	}
}