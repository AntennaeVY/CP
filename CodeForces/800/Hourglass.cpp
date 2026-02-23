#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int s, k, m;
		cin >> s >> k >> m;
		
		int c = m/k;
		m %= k;
		
		if (c % 2 == 1) {
			cout << max(0, min(s, k) - m) << "\n";
		} else {
			cout << max(0, s - m) << "\n";
		}
		
	}
}