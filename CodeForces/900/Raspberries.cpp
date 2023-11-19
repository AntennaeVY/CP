#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		bool ok = false;
		int even = 0, min_op = 10;
		
		for(int i=0; i < n; i++) {
			if (a[i] % k == 0)
				ok = true;
				
			even += (a[i] % 2 == 0);
			min_op = min(min_op, (k - a[i] % k) % k);
		}
		
		if (k == 4) {
			if (even >= 2)
				ok = true;
			else
				min_op = min(min_op, 2 - even);
		}
		
		cout << (ok ? 0 : min_op) << endl;
	}
}