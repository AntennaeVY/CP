#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), p(n+1, 0);
		
		for(int i=0; i < n; i++) {
			char x;
			cin >> x;
			
			a[i] = x - '0';
		}
		
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + a[i];
		}
		
		map<int, int> m;
		
		for(int i=0; i <= n; i++) {
			m[p[i] - i]++;
		}
		
		long long ans = 0;
		
		for(auto &[_, c] : m) {
			ans += (1LL*c*(c-1))/2;
		}
		
		cout << ans << endl;
	}
}