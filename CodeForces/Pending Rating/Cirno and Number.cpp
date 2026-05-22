#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	for(int _=1; _ <= t ; _++){
		long long a;
		int n;
		cin >> a >> n;
		
		vector<char> d(n);
		for(auto &di : d) cin >> di;
		
		// if (_ == 7168) {
			// cout << a << ";" << n << ";";
			// for(auto &di : d) cout << di <<",";
			// cout << endl;
		// }
		
		string s = to_string(a);
		int m = s.size();

		long long ans = LLONG_MAX;
		
		bool all=true;
		for(int i=0; i < m; i++) {
			bool can = false;
			for(auto di : d)
				can |= (di == s[i]); 
				
			all &= can;
		}
		
		if (all) {
			cout << 0 << "\n";
			continue;
		}
		
		if (m > 1) {
			long long b = stoll(string(m-1, d.back()));
			ans = min(ans, abs(b-a));
		}
		
		// a < b
		int i=0;
		while(i < m) {
			bool ok = false;
			
			for(auto di : d)
				ok |= (di == s[i]);
				
			// cout << i << bad << endl;
				
			if (!ok)
				break;
				
			i++;
		}
		
		// cout << i << endl;
		
		int j = i;
		
		while (i >= 0 && s[i] > d.back())
			i--;
			
		if (i == -1) {
			
			if (d[0] != '0') {
				long long b = stoll(string(m+1, d[0]));
				ans = min(ans, abs(a-b));
			} else {
				long long b = stoll(string(1, d[min(n-1, 1)]) + string(m, d[0]));
				ans = min(ans, abs(a-b));
			}
		} else {
			auto ub = upper_bound(d.begin(), d.end(), s[i]);
			
			if (ub != d.end()) {
				char x = *ub;
				
				// cout << i << endl;
				long long b = stoll(s.substr(0, i) + x + string(m-i-1, d[0]));
				ans = min(ans, abs(a-b));
				
				// cout << "b1 - " << b << endl;
			}
		} 
		
		
		// a > b
		if (s[j] < d[0])
			j = max(0, j-1);
			
		auto lb = lower_bound(d.begin(), d.end(), s[j]);
		
		if (lb != d.begin())
			lb = prev(lb);
			
		char x = *lb;
		
		// cout << x << " " << j << endl;
		
		long long b = stoll(s.substr(0, j) + x + string(m-j-1, d.back()));
		ans = min(ans, abs(a-b));
		
		// cout << "b2 - " << b << endl;
		
		cout << ans << "\n";
	}
}