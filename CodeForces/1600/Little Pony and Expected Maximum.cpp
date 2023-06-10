#include<bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	
	long double ans = 0;
	
	for(long double i=1; i <= m; i++) {
		ans += i * (powl(i/m, n) - powl((i-1)/m, n));
	}
	
	cout << ans << endl;
}