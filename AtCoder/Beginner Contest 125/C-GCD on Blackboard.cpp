#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
		
	vector<int> p(n+1, 0), s(n+1, 0);
	
	for(int i=0; i < n; i++) {
		p[i+1] = __gcd(p[i], a[i]);
	}
	
	for(int i=n-1; i >= 0; i--) {
		s[i] = __gcd(s[i+1], a[i]);
	}
	
	int ans = 0;
	 
	for(int i=0; i < n; i++) {
		ans = max(ans, __gcd(p[i], s[i+1]));
	}
	
	cout << ans << endl;
}