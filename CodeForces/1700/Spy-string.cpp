#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<string> a(n);
		for(auto &ai : a) cin >> ai;
		
		bool ok = true;
		string ans = "-1";
		
		if (n == 1) {
			cout << a[0] << endl;
			continue;
		}
		
		for(int p=0; p < m; p++) {
			char prev = '$';
			ok = true;
			
			for(int i=1; i < n; i++) {	
				int diff = 0;
			
				for(int j=0; j < m; j++) {
					if (j == p)
						continue;
						
					diff += (a[i][j] != a[0][j]);
				}
				
				if (diff > 1) {
					ok = false;
					break;
				}
				
				if (diff == 1) {
					if (prev == '$')
						prev = a[i][p];
					else if (prev != a[i][p])
						ok = false, prev = '$';
				}

			}			
			
			if (ok) {
				ans = a[0];
				ans[p] = (prev == '$' ? a[1][p] : prev);
				break;
			}
		}
		
		cout << ans << endl;
	}
}