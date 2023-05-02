#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int mn = 1e9, ans = 0;
		
		for(int i=n-1; i >= 0; i--) {
			if (a[i] > mn)
				ans++;
				
			mn = min(a[i], mn);
		}
		
		cout << ans << endl;
	}
}