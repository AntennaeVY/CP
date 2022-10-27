#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &it:a) cin >> it;
		
		sort(a.begin(), a.end());
		
		bool ok = true;
		
		for(int i=1; i < n; i++) {
			if (a[i] == a[i-1]) ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}