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
		
		vector<int> cnt(2e5+5, 0);
		vector<vector<int>> a(n);
		
		for(int i=0; i < n; i++) {
			int c;
			cin >> c;
			
			for(int j=0; j < c; j++) {
				int x;
				cin >> x;
				
				x--;
				
				a[i].push_back(x);
				cnt[x]++;
			}
		}
		
		int c = 0;
		
		for(int i=0; i < n; i++) {
			bool good = true;
			
			for(int j=0; j < a[i].size(); j++) {
				good &= cnt[a[i][j]] >= 2;
			}
			
			c += good;
		}
		
		if (c)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}