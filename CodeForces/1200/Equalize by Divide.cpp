#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int mn = 1e9+10, idx = -1;
		for(int i=0; i < n; i++) {
			if (a[i] < mn) {
				idx = i+1;
				mn = a[i];
			}
		}
		
		if (count(a.begin(), a.end(), a[0]) == n) {
			cout << "0\n";
			continue;
		} else if (mn == 1) {
			cout << "-1\n";
			continue;
		}
		
		vector<pair<int,int>> ans;
		
		while(true) {
			bool op = false;
			
			for(int i=0; i < n; i++) {
				if (a[i] > mn) {
					a[i] = (a[i] + mn - 1)/mn;
					
					ans.emplace_back(i+1, idx);
										
					if (a[i] < mn) {
						idx = i+1;
						mn = a[i];
					}
					
					op = true;
				}
			}
			
			if (!op)
				break;
		}
		
		cout << ans.size() << endl;
		for(auto &[i, j] : ans) 
			cout << i << " " << j << endl;
	}
}