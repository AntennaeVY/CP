#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int ans = 0;
		for(auto ai : a) ans ^= ai;
		
		if (ans == 0 || n % 2)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}
}