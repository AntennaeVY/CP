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
		
		for(int i=0; i < n; i++) {
			ans = (ans / a[i] + 1) * a[i];
		} 
		
		cout << ans << endl;
	}
}