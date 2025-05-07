#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, q;
		cin >> n >> q;
		
		vector<int> p(n);
		for(auto &pi : p) cin >> pi;
		
		vector<int> pos(n);
		for(int i=0; i < n; i++) {
			p[i]--;
			
			pos[p[i]] = i;
		}
		
		while(q--) {
			int l, r, k;
			cin >> l >> r >> k;
			
			l--, r--, k--;
			
			if (pos[k] > r || pos[k] < l) {
				cout << -1 << " ";
				continue;
			}
			
			int gt = 0, lt = 0;
			int sm = 0, bg = 0;
			
			int L = l, R = r;
			while(L <= R) {
				int m = (L+R)/2;
				
				if (pos[k] == m) {
					break;
				}
				
				if (pos[k] > m) {
					if (p[m] < k)
						sm++;
					else
						lt++;
						
					L = m+1;
				} 
				
				if (pos[k] < m) {
					if (p[m] > k)
						bg++;
					else
						gt++;
						
					R = m-1;	
				}
			}
			
			if (n - k - 1 - bg < gt || k - sm < lt) {
				cout << -1 << " ";
				continue;
			}
			
			cout << (max(gt, lt) - min(gt, lt)) * 2 + min(gt, lt) * 2 << " ";
		}
		
		cout << "\n";
	}
}