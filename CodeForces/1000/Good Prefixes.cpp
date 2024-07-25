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
		
		set<long long> s;
		long long sum = 0;
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			s.insert(a[i]);
			
			sum += a[i];
			
			if (sum % 2 == 0 && s.count(sum / 2))
				ans++;
		}
		
		cout << ans << endl;
	}
}