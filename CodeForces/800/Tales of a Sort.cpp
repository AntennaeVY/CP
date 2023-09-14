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
		
		for(int i=1; i < n; i++) {
			if (a[i-1] > a[i])
				ans = max(ans, a[i-1]);
		}
		
		cout << ans << endl;
	}
}