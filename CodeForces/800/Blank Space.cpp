#include<bits/stdc++.h>
using namespace std;

using ll = long long;

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
		
		int ans = 0, curr = 0;
		
		for(int i=0; i < n; i++) {
			if (a[i] == 1) {
				ans = max(ans, curr);
				curr = 0;
			} else {
				curr++;
			}
		}
		
		ans = max(ans, curr);
		cout << ans << endl;
	}
}