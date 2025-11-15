#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> l(m), r(m);
		for(int i=0; i < m; i++) {
			cin >> l[i] >> r[i];
			
			l[i]--, r[i]--;
		}
			
		vector<int> c(n+1);
		for(int i=0; i < m; i++) {
			c[l[i]]   += 1;
			c[r[i]+1] -= 1;
		}
		
		for(int i=0; i < n; i++) {
			c[i+1] += c[i];
		}
		
		int j = find(c.begin(), c.end(), m) - c.begin();
		
		// for(int i=0; i < n; i++)
			// cout << c[i] << " ";
		// cout << endl;
		
		vector<int> ans(n, -1);
		
		if (j < n) {
			ans[j] = 0;
			
			// cout << n << " " <<  m << endl;
			// cout << j << endl;
			
			int x=1;
			for(int i=0; i < n; i++) {
				if (ans[i] != -1)
					continue;
					
				ans[i] = x++;
			}
			
			// cout << 0 << endl;
			
		} else {
			int k=-1, kt = -1;
			
			for(int a=0; a < n-1; a++) {
				bool can = true;
				
				for(int b=0; b < m; b++) {
					if (a < l[b] || a > r[b])
						continue;
					
					can &= (a >= l[b] && a+1 <= r[b]);
				}
				
				if (can)
					k = a, kt = 0;
			}
			
			for(int a=1; a < n; a++) {
				bool can = true;
				
				for(int b=0; b < m; b++) {
					if (a < l[b] || a > r[b])
						continue;
					
					can &= (a-1 >= l[b] && a <= r[b]);
				}
				
				if (can)
					k = a, kt = 1;
			}
		
			if (k != -1) {
				
				if (kt == 0) {
					ans[k] = 0;
					ans[k+1] = 1;
				} else {
					ans[k] = 0;
					ans[k-1] = 1;
				}
				
				int x = 2;
				for(int i=0; i < n; i++) {
					if (ans[i] != -1)
						continue;
						
					ans[i] = x++;
				}
				
				// cout << 1 << endl;
				
			} else {
				
				ans[0] = 0;
				ans[1] = 2;
				ans[2] = 1;
				
				int x = 3;
				for(int i=3; i < n; i++) {
					ans[i] = x++;
				}
				
				// cout << "2/3" << endl;
			}
			
		}
		
		
		for(int i=0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}