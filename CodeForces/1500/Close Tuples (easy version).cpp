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

		sort(a.begin(), a.end());
		
		long long ans = 0;
		int l=0;
		
		for(int r=0; r < n; r++) {
			while(a[r] - a[l] > 2 && r-l+1 > 3) 
				l++;
				
			if (a[r] - a[l] <= 2 && r-l+1 >= 3) 
				ans += 1LL*(r-l)*(r-l-1)/2;
		}
		
		cout << ans << endl;
	}
}