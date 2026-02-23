#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int, int> m;
		for(int i=0; i < n; i++)
			m[a[i]] += 1;
			
		bool bad = false;
			
		for(int i=0; i < k; i++) {
			if (m[i] == 0) {
				bad = true;
				
				cout << i << "\n";
				break;
			}
		}
		
		if (bad)
			continue;
			
	
		cout << k-1 << "\n";
	}
}