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
		
		map<int, int> m;
		for(int i=0; i < n; i++) {
			m[a[i]]++;
		}
		
		int mx = 0;
		
		for(auto &[i, c] : m)
			mx = max(mx, c);
			
		cout << n - mx << endl;
	}
}