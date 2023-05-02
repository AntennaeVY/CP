#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
	
		vector<int> c(n);
		for(auto &ci : c) cin >> ci;
		
		sort(c.begin(), c.end());
		
		if (c[0] != 1) {
			cout << "NO" << endl;
			continue;
		}
		
		bool ok = true;
		long long sum = 1;
		
		for(int i=1; i < n; i++) {
			if (c[i] > sum)
				ok = false;
				
			sum += c[i];
		}
		
		cout << (ok ? "YES" : "NO") << endl;
 	}
}