#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		
		if (abs(n-m) > k || n < k && m < k) {
			cout << -1 << endl;
			continue;
		}
		
		string s = "";
		bool startZero = n > m;
		
		while(n > 0 || m > 0) {
			if (startZero) 
				s += string(min(k, n), '0'), n -= min(k, n);
			else
				s += string(min(k, m), '1'), m -= min(k, m);
				
			startZero = !startZero;
		}
		
		cout << s << endl;
	}
}