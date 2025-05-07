#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k, p;
		cin >> n >> k >> p;
		
		k = abs(k);
		
		if (k > n*p) {
			cout << -1 << '\n';
			continue;
		}
		
		cout << (k + p-1) / p << '\n';
	}
}