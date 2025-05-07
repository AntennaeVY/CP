#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<long long> a(n);
		for(auto &ai : a) cin >> ai;
	
		long long mn = *min_element(a.begin(), a.end());
		
		int mn_cnt = 0;
		long long gcd = 0;
		
		for(int i=0; i < n; i++) {
			mn_cnt += (a[i] == mn);
			
			if (a[i] != mn && a[i] % mn == 0)
				gcd = __gcd(gcd, a[i]);
		}
		
		
		
		if (mn_cnt >= 2 || gcd == mn) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}