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
		
		bool bad = false;
		int sum = accumulate(a.begin(), a.end(), 0);
		
		for(int i=0; i < n; i++) {
			if (sum % (n-i) != 0)
				continue;
				
			bad = false;
			int accum = 0;
			
			for(int j=0; j < n; j++) {
				if (accum == sum / (n-i))
					accum = 0;
				else if (accum > sum / (n-i))
					bad = true;
					
				accum += a[j];
			}
			
			if (accum > sum / (n-i))
				bad = true;
			
			if (!bad) {
				cout << i << endl;
				break;
			}
		}
		
		if (bad)
			cout << -1 << endl;
	}
}