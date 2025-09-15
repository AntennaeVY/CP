#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int ans = min({a,b,c});
		a -= ans, b -= ans, c -= ans;
		
		int l=0, r = 1e9+5;
		while(l+1 < r) {
			int m = l + (r-l)/2;
			
			if (a >= m && c >= m && (a+c-2*m) >= m)
				l = m;
			else
				r = m;
		}
		
		cout << ans + l << '\n';
		//actually ans is just min({a, c, (a+b+c)/3}) xddd
	}
}