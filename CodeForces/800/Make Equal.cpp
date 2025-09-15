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
		
		long long target = accumulate(a.begin(), a.end(), 0LL) / n;
		long long spare = 0;
		
		bool bad = false;
		
		for(int i=0; i < n; i++) {
			if (a[i] + spare < target)
				bad = true;
				
			spare += (a[i] - target);
		}
		
		cout << (bad ? "NO" : "YES") << "\n";
	}
}