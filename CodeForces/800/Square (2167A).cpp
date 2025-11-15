#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n=4;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		bool ok = true;
		for(int i=1; i < n; i++)
			ok &= a[i] == a[i-1];
			
		cout  << (ok ? "YES\n" : "NO\n");
	}
}