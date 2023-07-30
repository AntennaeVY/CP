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
		
		int top = *max_element(a.begin(), a.end());
		
		bool ok = true;
		for(int i=0; i < n; i++) {
			ok &= !((top - a[i]) % 2);
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}		
}