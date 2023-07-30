#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<ll> a(k);
		for(auto &it:a) cin >> it;
		
		ll diff = LLONG_MIN;
		bool ok = true;
		
		for(int i=1; i < k; i++) {
			if (a[i] - a[i-1] < diff) ok = false;
			
			diff = a[i] - a[i-1];
		}
		
		if (k >= 2) {
			ll known = a[1] - a[0];
			
			if (a[0] > (n-k+1)*known) ok = false;
		}
		
		cout << (ok ? "Yes" : "No") << endl;
	}
}