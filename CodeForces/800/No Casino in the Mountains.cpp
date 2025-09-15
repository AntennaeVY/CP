#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int l=0, p=-2;
		int ans = 0, sum = 0;
		
		for(int i=0; i < n; i++) {
			sum += a[i];
			
			while(sum > 0 || l-p == 1) {
				sum -= a[l];
				l++;
			}
			
			if (sum == 0 && i-l+1 == k ) {
				ans += 1;
				p = i;
				l=i+1, sum = 0;
			}
		}
		
		cout << ans << endl;
	}
}