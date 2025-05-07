#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		long long x, y;
		cin >> x >> y;
		
		if (x == y) {
			cout << -1 << "\n";
			continue;
		}
		
		if (x < y)
			swap(x, y);
		
		long long k = (1LL << 31) - x;
		
		assert(((x + k) & (y + k)) == 0);
		cout << k << endl;
	}
}