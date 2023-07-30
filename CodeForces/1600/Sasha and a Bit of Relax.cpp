#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	map<int, map<int, int>> m;
	vector<int> p(n+1, 0);
	
	for(int i=0; i < n; i++) {
		p[i+1] = (p[i] ^ a[i]);
	}
	
	for(int i=0; i <= n; i++) {
		m[i%2][p[i]]++;
	}
	
	long long ans = 0;
	
	for(int i=0; i <= 1; i++) {
		for(auto &[pi, x] : m[i]) {
			ans += (1LL * x * (x-1)) / 2;
		}
	}
	
	cout << ans << endl;
}