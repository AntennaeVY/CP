#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<long long> p(n);
	for(auto &pi : p) cin >> pi;
	
	vector<long long> rgcd(n), lgcd(n);
	
	lgcd[0] = p[0];
	for(int i=1; i < n; i++) {
		lgcd[i] = __gcd(lgcd[i-1], p[i]);
	}
	
	rgcd[n-1] = p[n-1];
	for(int i=n-2; i >= 0; i--) {
		rgcd[i] = __gcd(rgcd[i+1], p[i]);
	}
	
	long long ans = lgcd[n-1];
	
	for(int i=1; i < n-1; i++) {
		ans += min(rgcd[i], lgcd[i]);
	}
	
	cout << ans << '\n';
}