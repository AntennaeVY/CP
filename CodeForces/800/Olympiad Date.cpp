#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int,int> m;
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
	
		for(auto c : {0, 1, 0, 3, 2, 0, 2, 5}) {
			m[c]++;
		}
		
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			if (m.find(a[i]) != m.end()) {
				m[a[i]]--;
				
				bool can = true;
				
				for(auto &[x, c] : m) {
					can &= (c <= 0);
				}
				
				if (can) {
					ans = i+1;
					break;
				}
			}
		}
		
		cout << ans << endl;
	}
}