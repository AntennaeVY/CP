#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, q;
		cin >> n >> q;
		
		string a, b;
		cin >> a >> b;
		
		vector<vector<int>> pa(n+1, vector<int>(26)), pb(n+1, vector<int>(26));
		for(int i=0; i < n; i++) {
			int cha = a[i] - 'a';
			int chb = b[i] - 'a';
			
			
			for(int j=0; j < 26; j++) {
				pa[i+1][j] = pa[i][j] + int(cha == j);
				pb[i+1][j] = pb[i][j] + int(chb == j);
			}
		}
		
		while(q--) {
			int l, r;
			cin >> l >> r;
			
			int ans = 0;
			
			for(int i=0; i < 26; i++) {
				int cnta = pa[r][i] - pa[l-1][i];
				int cntb = pb[r][i] - pb[l-1][i];
				
				ans += max(0, cntb - cnta);
			}
			
			cout << ans << endl;
		}
	}
}