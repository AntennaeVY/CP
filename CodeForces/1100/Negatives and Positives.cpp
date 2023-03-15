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
		
		long long sum = 0;
		int mn_abs = 1e9, neg_cnt = 0;
		
		for(int i=0; i < n; i++) {
			neg_cnt += a[i] < 0;
			
			sum += abs(a[i]);
			mn_abs = min(mn_abs, abs(a[i]));
		}
		
		if (neg_cnt % 2 == 0)
			cout << sum << endl;
		else
			cout << sum - 2*mn_abs << endl;
		
	}
}