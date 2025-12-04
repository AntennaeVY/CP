#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> h(n);
	for(auto &hi : h) cin >> hi;
	
	map<int,long long> m;
	m[0] += 1;
	
	vector<long long> d(n);
	for(int i=1; i < n; i++) {
		int x = h[i] > h[i-1] ? 1 : -1;
		
		d[i] = d[i-1] + x;
		m[d[i]] += 1;
	}
	
	// for(auto &di : d)
		// cout << di << " ";
	// cout << endl;
	
	long long ans = n;
	for(auto &[cnt, c] : m) {
		// cout << cnt << " " << c * (c-1) / 2<< endl;
		ans += c * (c-1) / 2;
	}
	
	cout << ans << endl;
}