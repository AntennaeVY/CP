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
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<vector<int>> p(n+1, vector<int>(32, 0));
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < 32; j++) {
				p[i+1][j] += ((a[i] >> j) & 1);
			}
		}
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < 32; j++) {
				p[i+1][j] += p[i][j];
			}
		}
		
		int q;
		cin >> q;
		
		while(q--) {
			int l, k;
			cin >> l >> k;
			
			l--;
			
			int L=l, R=n;
			
			while(L+1 < R) {
				int M = L + (R-L)/2;
				
				int result = 0;
				
				for(int i=0; i < 32; i++) {
					if (p[M+1][i] - p[l][i] == M-l+1)
						result += (1 << i);
				}
				
				if (result >= k)
					L = M;
				else
					R = M;
			}
			
			if (L == l && a[l] < k)
				cout << -1 << " ";
			else
				cout << L+1 << " ";
		}
		
		cout << "\n";
	}
}