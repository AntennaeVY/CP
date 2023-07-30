#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	cout << fixed << setprecision(7);
	
	while(t--) {
		long long n, h;
		long double d;
		
		cin >> n >> d >> h;
		
		long double ans = 0;
	
		vector<long long> y(n);
		for(auto &yi : y) cin >> yi;
		
		y.push_back(1e18);
		
		for(int i=0; i < n; i++) {
			long double H = min(h, y[i+1] - y[i]),
				   b = d * (h - H) / h,
				   a = (d + b) * H / 2;
	
			ans += a;
		}		
		
		cout << ans << endl;
	}
}