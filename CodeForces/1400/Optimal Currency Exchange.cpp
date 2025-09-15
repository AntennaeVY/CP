#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, d, e;
	cin >> n >> d >> e;
	
	int ans = 1e9;
	
	for(int i=0; i <= n/d; i++) {
		ans = min(ans, (n - d*i) % (5*e));
	}
	
	cout << ans << "\n";
}