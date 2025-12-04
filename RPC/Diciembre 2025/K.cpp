#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> v(n), c(n);
	
	for(auto &vi : v) cin >> vi;
	for(auto &ci : c) cin >> ci;
	
	long long ans = 0;
	
	int j=0;
	for(int i=0; i < n; i++) {
		if (c[i] == c[j]) {
			if (v[i] > v[j])
				j = i;
		} else {
			ans += v[j];
			j = i;
		}
	}
	
	ans += v[j];
	
	cout << ans << "\n";
}