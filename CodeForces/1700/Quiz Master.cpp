#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		vector<vector<int>> divs(n, vector<int>());
		
		for(int i=0; i < n; i++) {
			for(int j=1; j <= m && 1LL*j*j <= a[i]; j++) {
				if (a[i] % j)
					continue;
					
				divs[i].push_back(j);
								
				if (a[i] / j != j && a[i] / j <= m)
					divs[i].push_back(a[i]/j);
			}
		}

		
		int ans = 1e9, need = m;
		vector<int> window(m+1, 0);
		
		for(int l=0, r=0; l < n; l++) {
			while(r < n && need) {
				for(int &div : divs[r]) {
					if (window[div] == 0)
						need--;
						
					window[div]++; 
				}
				
				r++;	
			}
			
			if (!need)
				ans = min(ans, a[r-1]-a[l]);
			
			for(int &div : divs[l]) {
				if (window[div] == 1)
					need++;
				
				window[div]--;
			}
		}
		
		cout << (ans == 1e9 ? -1 : ans) << endl;
	}
}