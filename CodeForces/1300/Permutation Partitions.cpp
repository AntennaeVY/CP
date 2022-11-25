#include<bits/stdc++.h>
using namespace std;

constexpr long long MOD = 998244353;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n), pos;
	for(auto &ai:a) cin >> ai; 
	
	cout << 1LL*n*(n+1)/2 - 1LL*(n-k)*(n-k+1)/2 << " ";
	
	for(int i=0; i < n; i++) {
		if (a[i] >= n-k+1 && a[i] <= n) 
			pos.push_back(i+1);	
	}
	
	long long ans = 1;
	
	for(int i=1; i < pos.size(); i++) {
		ans = ((ans%MOD) * ((pos[i]-pos[i-1])%MOD))%MOD;
	}
	
	cout << ans << endl;
}