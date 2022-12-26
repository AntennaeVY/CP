#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,m,k;
		cin >> n >> m >> k;
		
		vector<int> a(m);
		for(auto &ai:a) cin >> ai;
		
		if (n == 1) {
			cout << "YES" << endl;
			continue;
		}
	
		int leftovers = 0;
		bool can = true;
		
		for(int i=0; i < m; i++) {
			if (a[i] - n/k > 1)
				can = false;
			else if (a[i] - n/k == 1)
				leftovers++;
		}
		
		if (leftovers > n%k)
			can = false;
			
		cout << (can ? "YES" : "NO") << endl;
	}
}