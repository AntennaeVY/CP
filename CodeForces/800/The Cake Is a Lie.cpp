#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		
		cout << ((m-1) + m*(n-1) == k || (n-1) + n*(m-1) == k ? "YES" : "NO") << endl;
	}
}