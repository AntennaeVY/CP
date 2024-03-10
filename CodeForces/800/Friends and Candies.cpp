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
		
		long long sum = accumulate(a.begin(), a.end(), 0LL);
		
		if (sum % n != 0) {
			cout << -1 << endl;
			continue;
		}
		
		int x = sum/n, k = 0;
		
		for(int i=0; i < n; i++) {
			k += a[i] > x;
		}
		
		cout << k << endl;
	}
}