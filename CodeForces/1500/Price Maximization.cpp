#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		long long ans = 0;
	
		for(int i=0; i < n; i++) {
			cin >> a[i];
			
			ans += a[i] / k;
			a[i] %= k;			
		}
		
		sort(a.rbegin(), a.rend());
		
		for(int i=0, j=n-1; i < j; i++, j--) {
			while(a[i] + a[j] < k && i < j) j--;
			
			if (i == j)
				break;
				
			ans += 1;
		}
		
		cout << ans << endl;
	}
}