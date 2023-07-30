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
		
		int mx = *max_element(a.begin(), a.end());
		int mn = (1 << 10) - 1;
		
		for(int j=0; j < n; j++) {
			mx |= a[j];
			mn &= a[j];
		}		

		cout << mx - mn << endl;
	}
}