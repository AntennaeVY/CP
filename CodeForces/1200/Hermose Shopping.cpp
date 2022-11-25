#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		if (n >= 2*x) {
			cout << "YES" << endl;
			continue;
		}
		
		vector<int> b(a);
		sort(b.begin(), b.end());
		
		bool ok = true;
		
		for(int i=n-x; i < x; i++) {
			if (a[i] != b[i])
				ok = false;
		}
		
		if (ok)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
}