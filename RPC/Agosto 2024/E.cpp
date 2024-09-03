#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	long long ans = 0;
	
	vector<int> a(n), b(n);
	for(int i=0; i < n; i++) {
		cin >> a[i] >> b[i];
		
		ans = max(ans, 1LL * min(a[i], b[i]) * a[i] * b[i]);
	}
	
	cout << ans << endl;
}