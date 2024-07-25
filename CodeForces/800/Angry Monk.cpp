#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(k);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		long long ans = 0;
		
		for(int i=0; i < k-1; i++) {
			ans += 2*a[i] - 1;
		}
		
		cout << ans << endl;
	}
}