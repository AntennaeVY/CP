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
		
		a[0] += 1;
		
		long long ans = 1;
		
		for(int i=0; i < n; i++) {
			ans *= a[i];
		}
		
		cout << ans << endl;
	}
}