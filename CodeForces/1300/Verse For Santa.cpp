#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, s;
		cin >> n >> s;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		int max_value = 0, ans = 0;
		long long sum = 0;
		
		for(int i=0; i < n; i++) {
			sum += a[i];
		}
		
		if (sum <= s) {
			cout << 0 << endl;
			continue;
		}
		
		sum = 0;
		
		for(int i=0; i < n; i++) {
			sum += a[i];
			
			if (a[i] > max_value) {
				max_value = a[i];
				ans = i+1;
			}
			
			if (sum > s) break;
		}
		
		cout << ans << endl;		
	}
}