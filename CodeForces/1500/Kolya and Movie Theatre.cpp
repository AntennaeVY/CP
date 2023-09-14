#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n, m, d;
		cin >> n >> m >> d;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		set<pair<int, int>> s;
		
		long long ans = 0, sum = 0;
		
		for(int i=0; i < n; i++) {
			if (a[i] > 0) {
				s.insert({a[i], i+1});
				sum += a[i];
			}
				
			if (s.size() > m) {
				sum -= s.begin()->first;
				s.erase(s.begin());
			}
			
			ans = max(ans, sum - d*(i+1));
		}
		
		cout << ans << endl;
	}
}