#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());
	
		for(int i=0; i < k; i++) {
			a[i] = max(a[i], b[i]);
		}
		
		cout << accumulate(a.begin(), a.end(), 0LL) << endl;
	}
}