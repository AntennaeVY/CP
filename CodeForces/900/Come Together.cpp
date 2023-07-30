#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {	
		int xa, ya;
		cin >> xa >> ya;
		
		int xb, yb;
		cin >> xb >> yb;
		
		int xc, yc;
		cin >> xc >> yc;
		
		int ans = 1;
		
		ans += min(max(0, yb - ya), max(0, yc - ya));
		ans += min(max(0, ya - yb), max(0, ya - yc));
		ans += min(max(0, xb - xa), max(0, xc - xa));
		ans += min(max(0, xa - xb), max(0, xa - xc));
		
		cout << ans << endl;
		
	}
}