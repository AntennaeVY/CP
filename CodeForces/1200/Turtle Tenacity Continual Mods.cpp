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
		
		sort(a.begin(), a.end());
		
		if(a[0] != a[1]) {
			cout << "YES\n";
			continue;
		}
		
		bool ok = false;
		
		for(int i=0; i < n; i++) {
			ok |= (a[i] % a[0] != 0);
		}
		
		cout << (ok ? "YES" : "NO") << "\n";
	}
}