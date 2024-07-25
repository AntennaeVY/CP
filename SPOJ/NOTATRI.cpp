#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(true) {
		int n;
		cin >> n;
		
		if (n==0)
			break;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		int ans = 0;
	
		for(int i=0; i < n; i++) {
			for(int j=i+1; j < n; j++) {
				auto it = upper_bound(a.begin() + j, a.end(), a[i] + a[j]);	
				ans += a.end() - it;
			}
		}
		
		cout << ans << endl;
	}
}