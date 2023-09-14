#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<vector<int>> m(n);
		
		for(int i=0; i < n; i++) {
			int mi;
			cin >> mi;
			
			m[i].resize(mi);
			for(auto &mij : m[i]) cin >> mij;
			
			sort(m[i].begin(), m[i].end());
		}
		
		int min1 = 1e9, min2 = 1e9;
		
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			min1 = min(min1, m[i][0]);
			min2 = min(min2, m[i][1]);
			
			ans += m[i][1];
		}
		
		ans += min1 - min2;
		
		cout << ans << endl;
	}
}