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
			ans += a[i]%2 == a[i-1]%2;
		}	
		
		cout << ans << endl;
	}
}