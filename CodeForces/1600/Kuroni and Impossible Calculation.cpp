#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	if (n > m) {
		cout << 0 << endl;
		return 0;
	}
	
	int ans = 1;

	for(int i=0; i < n; i++) {
		for(int j=i+1; j < n; j++) {
			ans = ((ans % m) * (abs(a[i] - a[j]) % m)) % m;
		}
	}
	
	cout << ans << endl;
}