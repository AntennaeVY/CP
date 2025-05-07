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
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> kth(32, 0);
		for(int i=0; i < n; i++) {
			for(int j=0; j < 31; j++) {
				kth[j] += ((a[i] >> j) & 1);
			}
		}
		
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			long long sum = 0;
			
			for(int j=0; j < 31; j++) {
				if (((a[i] >> j) & 1))
					sum += 1LL * (n - kth[j]) * (1 << j);
				else
					sum += 1LL * kth[j] * (1 << j);
			}
			
			ans = max(ans, sum);
		}
		
		cout << ans << endl;
	}
}