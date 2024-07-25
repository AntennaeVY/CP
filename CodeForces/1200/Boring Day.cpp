#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, l, r;
		cin >> n >> l >> r;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int sum = 0, ans = 0;
		int L=0;
		
		for(int R=0; R < n; R++) {
			sum += a[R];
			
			while(sum > r)
				sum -= a[L++];
			
			if (sum >= l && sum <= r)
				ans++, sum = 0, L = R+1;
		}
				
		cout << ans << endl;
	}
}