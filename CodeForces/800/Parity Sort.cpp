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
		
		vector<int> b(n);
		iota(b.begin(), b.end(), 0);
		
		sort(b.begin(), b.end(), [&](int i, int j){ return a[i] < a[j]; });
		
		bool ok = true;
		
		for(int i=0; i < n; i++) {
			if (a[i] % 2 != a[b[i]] % 2)
				ok = false;
		}
		
		cout << (ok ? "YES" : "NO" ) << endl;
	}
}