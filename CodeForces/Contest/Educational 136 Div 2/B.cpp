#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		if (n == 1) {
			cout << a[0] << endl;
			continue;
		}
		
		bool multiple = false;
		

		vector<int> ans(n);
		ans[0] = a[0];
		
		for(int i=1; i < n; i++) {
			if (a[i] != 0 && ans[i-1] - a[i] >= 0) multiple = true;
			ans[i] = a[i] + ans[i-1];
		}

		
		if (multiple) {
			cout << -1 << endl;
			continue;
		}
		
		
		for (auto x : ans) {
			cout << x << " ";
		}
		
		cout << endl;
	}
}