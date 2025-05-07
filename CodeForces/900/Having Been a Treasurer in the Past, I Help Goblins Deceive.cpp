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
		
		string s;
		cin >> s;
		
		int m = count(s.begin(), s.end(), '-');
		int M = n - m;
		
		long long ans = 0;
		
		for(int i=1; i < m; i++) {
			ans = max(ans, 1LL * i * M * (m-i));
		}
		
		cout << ans << '\n';
	}
}