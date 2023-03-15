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
		
		int ans = 0, maxima = a[0];
		
		for(int i=1; i < n; i++) {
			if (maxima > a[i])
				ans = max(ans, __lg(maxima - a[i]) + 1);
				
			maxima = max(maxima, a[i]);
		}
		
		cout << ans << endl;
	}
}