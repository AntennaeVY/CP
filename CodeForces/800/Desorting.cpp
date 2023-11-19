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
		
		int ans = 1e9;
		
		for(int i=1; i < n; i++) {
			if (a[i] < a[i-1])
				ans = 0;
			else
				ans = min(ans, (a[i] - a[i-1])/2 + 1);
		}
		
		cout << ans << endl;
	}
}